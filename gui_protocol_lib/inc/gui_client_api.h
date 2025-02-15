#ifndef GUI_CLIENT_API_H
#define GUI_CLIENT_API_H

/* System Includes */
#include <memory>
#include <inttypes.h>

/* Shared includes */
#include "thread_safe_queue.h"

namespace GuiProtocol
{
    enum class GuiClientState_E
    {
        INITIALIZED,
        WIDGET_LIST_REQUESTED,
        WIDGET_LIST_RECEIVED,
    };

    struct Message_T
    {
        std::unique_ptr<char[]> data;
        uint16_t size;
    };

    class GuiClient_C
    {
        public:
            GuiClient_C();
            ~GuiClient_C();
            void ProcessReceivedMessage(std::unique_ptr<char[]>& msg, uint16_t size);
            void ProcessTimedActivities();
            void SendWidgetListRequest();

            /* Callbacks */
            virtual void OnWidgetListReplyReceived() = 0;

        private:
            uint64_t GetCurrentTimeMs();
            void ProcessStateMachine();

            /* Callbacks*/
            virtual void SendMessage() = 0;

            /* Member Variables */
            GuiClientState_E _state = GuiClientState_E::INITIALIZED;
            ThreadSafeQueue_C<Message_T> _msgQueue;
            bool _widgetListRequested = false;
            bool _widgetListReceived = false;

    };
}

#endif // GUI_CLIENT_API_H