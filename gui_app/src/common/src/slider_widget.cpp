/* Project includes */
#include "stdafx.h"
#include "slider_widget.h"

SliderWidget_C::SliderWidget_C()
{

}

SliderWidget_C::~SliderWidget_C()
{

}

void SliderWidget_C::ShowWidget()
{
    // ShowWidget override
    ImGui::SliderFloat(_sliderLabel.c_str(), &_sliderValue, _sliderMin, _sliderMax);
}

bool SliderWidget_C::SetWidgetValue(const char* label, float* value, float min, float max)
{
    // Check for invalid input for the slider values, abort if so
    if (!label || !value || min >= max)
    {
        _sliderLabel.clear();
        return false;
    }

    _sliderLabel = label;
    _sliderValue = *value;
    _sliderMin = min;
    _sliderMax = max;
    return true;
}
