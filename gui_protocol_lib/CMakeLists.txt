cmake_minimum_required( VERSION 3.29 )
set(CMAKE_CXX_STANDARD 17 )
set(CMAKE_CXX_STANDARD_REQUIRED True )

project( gui_protocol_library )

# Define the library
include(files.cmake)
add_library(${PROJECT_NAME} SHARED)

include_directories( ${CMAKE_SOURCE_DIR}/shared/common/inc )
if( ${CMAKE_SYSTEM_NAME} STREQUAL "Windows" )
    include_directories( ${CMAKE_SOURCE_DIR}/shared/platform/windows/inc )
elseif( ${CMAKE_SYSTEM_NAME} STREQUAL "Linux" )
    include_directories( ${CMAKE_SOURCE_DIR}/shared/platform/linux/inc )
endif()

# Include the headers
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

# Add the source files
target_sources(${PROJECT_NAME} PUBLIC 
    ${GUI_PROTOCOL_LIBRARY_SRC}
    ${GUI_PROTOCOL_LIBRARY_WIN}
    ${GUI_PROTOCOL_LIBRARY_LINUX}
)