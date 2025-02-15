#include "stdafx.h"
#include "property_consumer.h"

PropertyConsumer_C::PropertyConsumer_C(PropertyConsumerInitParams_C initParams) : _producerInfo(initParams.producerInfo), _guiAppInfo(initParams.guiAppInfo)
{
    _transport = UdpTransportFactory::CreateTransport();
    _transport->InitializeSocket(initParams.myIp, initParams.myPort);
}

PropertyConsumer_C::~PropertyConsumer_C()
{

}

void PropertyConsumer_C::RunTest()
{
    while (false == _isQuit)
    {
        if (true == _transport->PollReceiveSocket())
        {
            HandleMessage();
        }
    }
}

void PropertyConsumer_C::HandleMessage()
{
    
}

void PropertyConsumer_C::UpdateGuiWidget()
{
    std::vector<uint8_t> msg;
    _transport->TransportSendMessage(_guiAppInfo.destIp, _guiAppInfo.destPort, msg);
}