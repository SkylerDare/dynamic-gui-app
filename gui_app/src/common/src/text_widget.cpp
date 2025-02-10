/* Project includes */
#include "stdafx.h"
#include "text_widget.h"

TextWidget_C::TextWidget_C()
{

}

TextWidget_C::~TextWidget_C()
{

}

void TextWidget_C::ShowWidget()
{
    //std::cout << "Showing text widget with value: " << _widgetText << "\n";
    ImGui::Text(_widgetText.c_str());
}

bool TextWidget_C::SetWidgetValue(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    
    // Calculate required size
    int size = std::vsnprintf(nullptr, 0, format, args);
    va_end(args);

    if (size <= 0) {
        _widgetText.clear();
        return false;
    }

    std::vector<char> buffer(size + 1);  // Dynamic buffer
    va_start(args, format);
    std::vsnprintf(buffer.data(), buffer.size(), format, args);
    va_end(args);

    _widgetText = buffer.data();  // Assign formatted text
    return true;
}