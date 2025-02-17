#ifndef LINUX_UDP_TRANSPORT_H_
#define LINUX_UDP_TRANSPORT_H_

/* System Includes */
#include <iostream>
#include <vector>
#include <memory>
#include <stdlib.h>
#include <memory.h>

/* Project includes */
#include "transport_interface.h"

/* System includes */
#include <iomanip>

/* Platform includes */
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <termios.h>
#include <fcntl.h>
#include <time.h>

class LinuxUdpTransport : public TransportInterface
{
    public: 
        LinuxUdpTransport();
        ~LinuxUdpTransport() override;

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
        int32_t _socketDescriptor;

};
#endif // LINUX_UDP_TRANSPORT_H_