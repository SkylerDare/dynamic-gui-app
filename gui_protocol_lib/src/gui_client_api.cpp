#include "gui_client_api.h"

/* System includes */
#include <chrono>
namespace GuiProtocol
{
    GuiClient_C::GuiClient_C()
    {

    }

    GuiClient_C::~GuiClient_C()
    {

    }

    void GuiClient_C::ProcessReceivedMessage(std::unique_ptr<char[]>& msg, uint16_t size)
    {
        Message_T rxMsg = {std::move(msg), size};
        _msgQueue.AddMessageToQueue(std::move(rxMsg));
    }

    void GuiClient_C::ProcessTimedActivities()
    {
        if (false == _msgQueue.IsQueueEmpty())
        {
            auto msg = _msgQueue.GetMessageFromQueue();
            // Process msg based on msg id 
        }
        else 
        {
            ProcessStateMachine();
        }
    }

    void GuiClient_C::SendWidgetListRequest()
    {
        if (GuiClientState_E::INITIALIZED == _state)
        {
            // Generate Serialized Widget List Request msg
            SendMessage();
            _widgetListRequested = true;
        }
    }

    uint64_t GuiClient_C::GetCurrentTimeMs()
    {
        return static_cast<uint64_t>(
            std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::steady_clock::now().time_since_epoch()
            ).count()
        );
    }

    void GuiClient_C::ProcessStateMachine()
    {
        switch (_state)
        {
            case GuiClientState_E::INITIALIZED:
                if (true == _widgetListRequested)
                {
                    _state = GuiClientState_E::WIDGET_LIST_REQUESTED;
                } 
                break;

            case GuiClientState_E::WIDGET_LIST_REQUESTED:
                // Check for a timeout 
                if (true == _widgetListReceived)
                {
                    _state = GuiClientState_E::WIDGET_LIST_RECEIVED;
                } 
                break;

            case GuiClientState_E::WIDGET_LIST_RECEIVED:
                break;
                
            default:
                break;
        }
    }
}