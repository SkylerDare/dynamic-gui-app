#ifndef DYNAMIC_GUI_H
#define DYNAMIC_GUI_H

#include "stdafx.h"

class DynamicGui_C 
{
    public: 
        DynamicGui_C();
        ~DynamicGui_C();

        /**
         * @brief Initializes and runs the GUI app blocking function that exits upon window close. 
         * 
         * @return true 
         * @return false 
         */
        bool Run();

        /**
         * @brief Set the Config File
         * 
         * @param configFilePath absolute file path to a config file 
         * 
         * @return true false
         */
        bool SetConfigFile(const std::string& configFilePath);

    private: 
        /* Functions */

        /**
         * @brief Initializes SDL backend for GUI app
         * 
         * @return true 
         * @return false 
         */
        bool Initialize();

        /**
         * @brief Displays the GUI window
         * 
         * @return true false
         * @retval true - Window was displayed
         * @retval false - Window was never displayed
         */
        bool ShowGui();

        /**
         * @brief Parses json data from the member variable _jsonData
         * 
         */
        void ParseJsonData();

        /**
         * @brief Performs cleanup of GUI app backend resources
         * 
         */
        void DeInitialize();

        /* Variables */
        bool                                            _isRunning                      = false;
        bool                                            _initialized                    = false;
        uint16_t                                        _widgetKeyCount                 = 0;
        std::map<uint16_t, WidgetInfo_T>                _widgetMap;
        std::ifstream                                   _configFile;
        std::string                                     _configFilePath;
        nlohmann::json                                  _jsonData;
        std::string                                     _glslVersion;
        std::string                                     _mainWindowName;
        std::string                                     _widgetWindowName;
        SDL_GLContext                                   _glContext;
        SDL_Window*                                     _window;

};

#endif // DYNAMIC_GUI_H