#ifndef BUTTON_WIDGET_H
#define BUTTON_WIDGET_H

#include "stdafx.h"
#include "widget_interface.h"

class ButtonWidget_C : public WidgetInterface_I
{
public:
    ButtonWidget_C();
    ~ButtonWidget_C();
    void ShowWidget() override;
    bool SetWidgetValue(const char* label);

private:
    std::string _buttonLabel;
};
#endif // BUTTON_WIDGET_H
