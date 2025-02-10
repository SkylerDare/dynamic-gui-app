#ifndef TEXT_WIDGET_H
#define TEXT_WIDGET_H

#include "stdafx.h"
#include "widget_interface.h"

class TextWidget_C : public WidgetInterface_I
{
    public:
        TextWidget_C();
        ~TextWidget_C();
        void ShowWidget() override;
        bool SetWidgetValue(const char* format, ...);

    private:
        std::string _widgetText;
};
#endif // TEXT_WIDGET_H