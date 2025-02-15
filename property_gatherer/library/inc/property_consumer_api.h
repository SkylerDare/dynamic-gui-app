#ifndef PROPERTY_CONSUMER_API_H
#define PROPERTY_CONSUMER_API_H

/* System Includes */
#include <string>
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <memory>
#include <inttypes.h>

/* Project Includes */
#include "messages.h"

namespace PropertyGatherer
{
    class PropertyConsumer_C
    {
        public:
            PropertyConsumer_C();
            ~PropertyConsumer_C();

        private:
            MessageSerializer _msgSerializer; 
    };
}

#endif // PROPERTY_CONSUMER_API_H