#ifndef CUSTOM_TYPES_H
#define CUSTOM_TYPES_H

/* System includes */
#include <any>

/**
 * @brief Used to define the type of a widget (i.e Text Box, Slider, Button, etc..)
 * 
 */
enum class WidgetTypes_E
{
    TEXT,
};

/**
 * @brief Used to store widget info
 * 
 */
struct WidgetInfo_T
{
    WidgetTypes_E   type; 
    std::any        value;
};
#endif // CUSTOM_TYPES_H