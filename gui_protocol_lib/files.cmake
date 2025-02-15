file(GLOB GUI_PROTOCOL_LIBRARY_SRC 
    "src/*"
    "${CMAKE_SOURCE_DIR}/shared/common/src/*"
)

file(GLOB GUI_PROTOCOL_LIBRARY_INC 
    "inc/*"
    "${CMAKE_SOURCE_DIR}/shared/common/inc/*"
)

if( ${CMAKE_SYSTEM_NAME} STREQUAL "Windows" )
file(GLOB GUI_PROTOCOL_LIBRARY_WIN 
    "${CMAKE_SOURCE_DIR}/shared/platform/windows/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/shared/platform/windows/inc/*.h"
)
else() 
set( GUI_PROTOCOL_LIBRARY_WIN )
endif()

if( ${CMAKE_SYSTEM_NAME} STREQUAL "Linux" )
file(GLOB GUI_PROTOCOL_LIBRARY_LINUX 
    "${CMAKE_SOURCE_DIR}/shared/platform/linux/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/shared/platform/linux/inc/*.h"
)
else() 
set( GUI_PROTOCOL_LIBRARY_LINUX )
endif()

set( _GUI_PROTOCOL_LIBRARY_SOURCEFILES
    ${GUI_PROTOCOL_LIBRARY_SRC}
    ${GUI_PROTOCOL_LIBRARY_INC}
    ${GUI_PROTOCOL_LIBRARY_WIN}
    ${GUI_PROTOCOL_LIBRARY_LINUX}
    files.cmake
)

source_group( "" FILES ${GUI_PROTOCOL_LIBRARY_TOPLEVEL})
source_group( gui_protocol_library/src FILES ${GUI_PROTOCOL_LIBRARY_SRC})
source_group( gui_protocol_library/inc FILES ${GUI_PROTOCOL_LIBRARY_INC})
source_group( gui_protocol_library/platform/windows FILES ${GUI_PROTOCOL_LIBRARY_WIN})
source_group( gui_protocol_library/platform/linux FILES ${GUI_PROTOCOL_LIBRARY_LINUX})