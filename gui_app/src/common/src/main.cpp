/* Project includes */
#include "stdafx.h"
#include "command_line_parser.h"
#include "dynamic_gui.h"

int main(int argc, char** argv)
{
    CommandLineParser_C commandLineParser(argc, argv);
    DynamicGui_C app;

    if (true == commandLineParser.CmdOptionExists("-f") && 
        false == commandLineParser.GetCmdOption("-f").empty())
    {
        app.SetConfigFile(commandLineParser.GetCmdOption("-f"));
        if (false == app.Run())
        {
            return -1;
        }
    }
    else
    {
        std::cout << "Provide a config file via the -f option. (TODO: Allow user to create config via GUI app)\n";
        std::cout << "Example: gui_app.exe -f ..\\..\\..\\gui_app\\config_files\\gui_app.json\n";
    }

    return 0;
}