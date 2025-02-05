#ifndef _WINDOWS_UDP_TRANSPORT_H_
#define _WINDOWS_UDP_TRANSPORT_H_

/* System Includes */
#include <iostream>
#include <vector>

/* Project includes */
#include "transport_interface.h"

/* Platform includes */
#include <Winsock2.h>
#undef SendMessage

class WindowsUdpTransport : public TransportInterface
{
    public: 
        WindowsUdpTransport();
        ~WindowsUdpTransport() override;

        bool InitializeSocket(const std::string& ipAddress, uint16_t port) override;

        // Deinitialize the UDP transport layer.
        void DeInitialize() override;

        // Send a message through the UDP transport layer.
        int32_t TransportSendMessage(const std::string& destIpAddr,
                                        uint16_t destPort,
                                        const std::vector<uint8_t>& message) override;
        
        // Receive a message 
        int32_t ReceiveMessage(std::unique_ptr<char[]>& inputBuffer,
                                uint16_t inputBufferSize,
                                std::string& senderIp,
                                uint16_t& senderPort) override;

        // Poll the receive socket
        bool PollReceiveSocket() override;

    private:
        SOCKET _socketDescriptor;

};
#endif // _WINDOWS_UDP_TRANSPORT_H_