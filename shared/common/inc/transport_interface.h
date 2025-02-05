#ifndef _TRANSPORT_INTERFACE_H_
#define _TRANSPORT_INTERFACE_H_

/* System Includes */
#include <iostream>
#include <string>

/* Project Includes*/

class TransportInterface
{
    public:
        virtual ~TransportInterface() = default;

        virtual bool InitializeSocket(const std::string& ipAddress, uint16_t port) = 0;

        // Deinitialize the UDP transport layer.
        virtual void DeInitialize() = 0;

        // Send a message through the UDP transport layer.
        virtual int32_t TransportSendMessage(const std::string& destIpAddr,
                                            uint16_t destPort,
                                            const std::vector<uint8_t>& message) = 0;
        
        // Receive a message 
        virtual int32_t ReceiveMessage(std::unique_ptr<char[]>& inputBuffer,
                                        uint16_t inputBufferSize,
                                        std::string& senderIp,
                                        uint16_t& senderPort) = 0;

        // Poll the receive socket
        virtual bool PollReceiveSocket() = 0;
    
    private:
        int32_t _socketDescriptor;
};

#endif // _TRANSPORT_INTERFACE_H_