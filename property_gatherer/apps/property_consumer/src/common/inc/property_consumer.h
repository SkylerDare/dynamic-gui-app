#ifndef PROPERTY_CONSUMER_H
#define PROPERTY_CONSUMER_H

#include "stdafx.h"
#include "transport_factory.h"

struct PropertyProducerInfo_T
{
    std::string destIp;
    uint16_t destPort;
};

struct GuiAppInfo_T
{
    std::string destIp;
    uint16_t destPort;
};

struct PropertyConsumerInitParams_C
{
    PropertyProducerInfo_T producerInfo;
    GuiAppInfo_T guiAppInfo;
    std::string myIp;
    uint16_t myPort;
};

class PropertyConsumer_C 
{
    public:
        PropertyConsumer_C(PropertyConsumerInitParams_C initParams);
        ~PropertyConsumer_C();
        void RunTest();
        void HandleMessage();
        void UpdateGuiWidget();

    private:
        std::shared_ptr<TransportInterface> _transport;
        PropertyProducerInfo_T _producerInfo;
        GuiAppInfo_T _guiAppInfo;
        bool _isQuit = false;
};

#endif // PROPERTY_CONSUMER_H