#ifndef WIDGET_INTERFACE_H
#define WIDGET_INTERFACE_H

#include "stdafx.h"

class WidgetInterface_I 
{
    public:
        virtual ~WidgetInterface_I() {}

        virtual void ShowWidget() = 0;

};
#endif // WIDGET_INTERFACE_H