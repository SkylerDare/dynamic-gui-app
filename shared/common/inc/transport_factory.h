#ifndef TRANSPORT_FACTORY_H
#define TRANSPORT_FACTORY_H

#include "transport_interface.h"
#ifdef _WIN32
#include "windows_udp_transport.h"
#elif defined(__linux__)
#include "linux_udp_transport.h"
#else
#error "Unsupported platform"
#endif

#include <memory> // For std::shared_ptr

class UdpTransportFactory {
public:
    static std::shared_ptr<TransportInterface> CreateTransport() {
#ifdef _WIN32
        return std::make_shared<WindowsUdpTransport>();
#elif defined(__linux__)
        return std::make_shared<LinuxUdpTransport>();
#endif
    }
};

#endif // TRANSPORT_FACTORY_H
