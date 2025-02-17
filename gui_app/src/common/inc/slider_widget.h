#ifndef SLIDER_WIDGET_H
#define SLIDER_WIDGET_H

#include "stdafx.h"
#include "widget_interface.h"

class SliderWidget_C : public WidgetInterface_I
{
public:
    SliderWidget_C();
    ~SliderWidget_C();
    void ShowWidget() override;
    bool SetWidgetValue(const char* label, float* value, float min, float max);

private:
    std::string _sliderLabel;
    float _sliderValue;
    float _sliderMin;
    float _sliderMax;
};
#endif // SLIDER_WIDGET_H
