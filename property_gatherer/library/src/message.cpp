#include "messages.h"

namespace PropertyGatherer
{
    MessageSerializer::MessageSerializer()
    {

    }

    MessageSerializer::~MessageSerializer()
    {

    }

    void MessageSerializer::SerializeHeader(Header_T& header, std::vector<uint8_t>& outBuff)
    {
        uint8_t bufSize = outBuff.size();

        /* Serialize Protocol ID High */
        outBuff.resize(bufSize + sizeof(header.protocolIdHigh));
        std::memcpy(outBuff.data() + bufSize, &header.protocolIdHigh, sizeof(header.protocolIdHigh));
        bufSize = outBuff.size(); 

        /* Serialize Protocol ID Low */
        outBuff.resize(bufSize + sizeof(header.protocolIdLow));
        std::memcpy(outBuff.data() + bufSize, &header.protocolIdLow, sizeof(header.protocolIdLow));
        bufSize = outBuff.size(); 

        /* Serialize Message ID */
        outBuff.resize(bufSize + sizeof(header.messageId));
        std::memcpy(outBuff.data() + bufSize, &header.messageId, sizeof(header.messageId));
        bufSize = outBuff.size(); 
    }

    uint16_t MessageSerializer::Serialize(GetValueReq_T& pMessage, std::vector<uint8_t>& outBuff)
    {
        SerializeHeader(pMessage.header, outBuff);
        uint16_t bufSize = outBuff.size();

        /* Serialize Max Response Length */
        outBuff.resize(bufSize + sizeof(pMessage.maxRespLen));
        std::memcpy(outBuff.data() + bufSize, &pMessage.maxRespLen, sizeof(pMessage.maxRespLen));
        bufSize = outBuff.size(); 

        /* Serialize Number of Requested Properties */
        outBuff.resize(bufSize + sizeof(pMessage.numReqProp));
        std::memcpy(outBuff.data() + bufSize, &pMessage.numReqProp, sizeof(pMessage.numReqProp));
        bufSize = outBuff.size(); 

        /* Serialize List of Requested Property Ids */
        for (auto& propertyId : pMessage.propIds)
        {
            outBuff.resize(bufSize + sizeof(propertyId));
            std::memcpy(outBuff.data() + bufSize, &propertyId, sizeof(propertyId));
            bufSize = outBuff.size(); 
        }

        return bufSize;
    }

    uint16_t MessageSerializer::Serialize(GetValueReply_T& pMessage, std::vector<uint8_t>& outBuff)
    {
        SerializeHeader(pMessage.header, outBuff);
        uint16_t bufSize = outBuff.size();

        /* Serialize List of Requested Property Ids */
        for (auto& properties : pMessage.propValues)
        {
            bufSize += SerializeVariant(properties, outBuff);
        }

        /* Serialize status */
        bufSize = outBuff.size();
        outBuff.resize(bufSize + sizeof(pMessage.status));
        std::memcpy(outBuff.data() + bufSize, &pMessage.status, sizeof(pMessage.status));
        bufSize = outBuff.size(); 
        
        return bufSize;
    }

    uint16_t MessageSerializer::SerializeVariant(const PropertyStorageVariant& variant, std::vector<uint8_t>& outBuff)
    {
        // Serialize the type index (or type identifier)
         uint8_t typeIndex = static_cast<uint8_t>(variant.index());
         outBuff.push_back(typeIndex);  // Store the type index at the beginning of the serialized data

        // switch (typeIndex)
        // {
        //     case UNSIGNED_8_BIT_INT:
        //         outBuff.resize(outBuff.size() + sizeof(uint8_t));
        //         std::memcpy();
                
        // }
        return std::visit([&outBuff](const auto& value) -> uint16_t
        {
            using T = std::decay_t<decltype(value)>;

            if constexpr (std::is_same_v<T, std::string>)
            {
                size_t oldSize = outBuff.size();
                size_t strSize = value.size() + 1; // +1 for null terminator

                outBuff.resize(oldSize + strSize);
                std::memcpy(outBuff.data() + oldSize, value.c_str(), strSize); // Include null terminator

                return static_cast<uint16_t>(strSize);
            }
            else
            {
                auto bufSize = outBuff.size();
                outBuff.resize(bufSize + sizeof(T));
                std::memcpy(outBuff.data() + bufSize, &value, sizeof(T));
                return sizeof(T);
            }
        }, variant);
    }

    void MessageSerializer::DeserializeHeader(Header_T& header, std::vector<uint8_t>& msgBuf)
    {
        uint8_t bufIndex = 0;

        /* Deserialize Protocol ID High */
        std::memcpy(&header.protocolIdHigh, msgBuf.data() + bufIndex, sizeof(header.protocolIdHigh));
        bufIndex += sizeof(header.protocolIdHigh);

        /* Deserialize Protocol ID Low */
        std::memcpy(&header.protocolIdLow, msgBuf.data() + bufIndex, sizeof(header.protocolIdLow));
        bufIndex += sizeof(header.protocolIdLow);

        /* Deserialize Message ID */
        std::memcpy(&header.messageId, msgBuf.data() + bufIndex, sizeof(header.messageId));
        bufIndex += sizeof(header.messageId);
    }

    bool MessageSerializer::Deserialize(GetValueReq_T& pMessage, std::vector<uint8_t>& msgBuf)
    {
        DeserializeHeader(pMessage.header, msgBuf);
        uint16_t bufIndex = sizeof(pMessage.header);

        /* Deserialize Max Response Length */
        std::memcpy(&pMessage.maxRespLen, msgBuf.data() + bufIndex, sizeof(pMessage.maxRespLen));
        bufIndex += sizeof(pMessage.maxRespLen);

        /* Deserialize Number of Requested Properties */
        std::memcpy(&pMessage.numReqProp, msgBuf.data() + bufIndex, sizeof(pMessage.numReqProp));
        bufIndex += sizeof(pMessage.numReqProp);

        /* Deserialize List of Requested Property Ids */
        pMessage.propIds.resize(pMessage.numReqProp);
        for (auto& propertyId : pMessage.propIds)
        {
            std::memcpy(&propertyId, msgBuf.data() + bufIndex, sizeof(propertyId));
            bufIndex += sizeof(propertyId); 
        }

        return true;
    }

    bool MessageSerializer::Deserialize(GetValueReply_T& pMessage, std::vector<uint8_t>& msgBuf)
    {
        DeserializeHeader(pMessage.header, msgBuf);
        uint16_t bufIndex = sizeof(pMessage.header);

        /* Deserialize variants */
        while (bufIndex < (msgBuf.size() - sizeof(pMessage.status)))
        {
            pMessage.propValues.push_back(DeserializeVariant(msgBuf, bufIndex));
        }

        /* Deserialize status */
        std::memcpy(&pMessage.status, msgBuf.data() + bufIndex, sizeof(pMessage.status));
        bufIndex += sizeof(pMessage.status);

        return true;
    }

    PropertyStorageVariant MessageSerializer::DeserializeVariant(std::vector<uint8_t>& inBuff, uint16_t& index)
    {
        // Read the type index (which type was serialized)
        uint8_t typeIndex = inBuff[index++];
        
        PropertyStorageVariant result;

        // Based on the type index, read the appropriate data from the buffer
        switch (typeIndex) {
            // case 0: { // int8_t
            //     int8_t val = static_cast<int8_t>(inBuff[index++]);
            //     result = val;
            //     break;
            // }
            // case 1: { // int16_t
            //     int16_t val = static_cast<int16_t>(inBuff[index++] | (inBuff[index++] << 8));
            //     result = val;
            //     break;
            // }
            // case 2: { // int32_t
            //     int32_t val = static_cast<int32_t>(inBuff[index++] | (inBuff[index++] << 8) |
            //                                     (inBuff[index++] << 16) | (inBuff[index++] << 24));
            //     result = val;
            //     break;
            // }
            // case 3: { // int64_t
            //     int64_t val = static_cast<int64_t>(inBuff[index++] | (inBuff[index++] << 8) |
            //                                     (inBuff[index++] << 16) | (inBuff[index++] << 24) |
            //                                     (inBuff[index++] << 32) | (inBuff[index++] << 40) |
            //                                     (inBuff[index++] << 48) | (inBuff[index++] << 56));
            //     result = val;
            //     break;
            // }
            case UNSIGNED_8_BIT_INT: { // uint8_t
                uint8_t val = inBuff[index++];
                result = val;
                break;
            }
            // case 5: { // uint16_t
            //     uint16_t val = static_cast<uint16_t>(inBuff[index++] | (inBuff[index++] << 8));
            //     result = val;
            //     break;
            // }
            // case 6: { // uint32_t
            //     uint32_t val = static_cast<uint32_t>(inBuff[index++] | (inBuff[index++] << 8) |
            //                                         (inBuff[index++] << 16) | (inBuff[index++] << 24));
            //     result = val;
            //     break;
            // }
            // case 7: { // uint64_t
            //     uint64_t val = static_cast<uint64_t>(inBuff[index++] | (inBuff[index++] << 8) |
            //                                         (inBuff[index++] << 16) | (inBuff[index++] << 24) |
            //                                         (inBuff[index++] << 32) | (inBuff[index++] << 40) |
            //                                         (inBuff[index++] << 48) | (inBuff[index++] << 56));
            //     result = val;
            //     break;
            // }
            // case 8: { // float
            //     float val;
            //     std::memcpy(&val, &inBuff[index], sizeof(val));
            //     index += sizeof(val);
            //     result = val;
            //     break;
            // }
            case STRING: { // std::string
                uint16_t startIdx = index;
                while (index < inBuff.size() && inBuff[index] != '\0') 
                {
                    ++index;
                }
                std::string str(reinterpret_cast<const char*>(&inBuff[startIdx]), index - startIdx);
                ++index;
                result = str;
                break;
            }
            default:
                throw std::runtime_error("Unknown type index during deserialization.");
        }

        return result;
    }
}