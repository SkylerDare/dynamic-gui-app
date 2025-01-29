cmake_minimum_required( VERSION 3.29 )
set(CMAKE_CXX_STANDARD 17 )
set(CMAKE_CXX_STANDARD_REQUIRED True )

project( gui_app )

find_package(OpenGL REQUIRED)

# Set library / binary output directory 
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 3rd party includes 
set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(3rd_party/nlohmann_json)
add_subdirectory(3rd_party/SDL)
include_directories(3rd_party/imgui)

# Project includes 
include_directories( ${CMAKE_CURRENT_LIST_DIR}/common/inc )
if( ${CMAKE_SYSTEM_NAME} STREQUAL "Windows" )
    include_directories( ${CMAKE_CURRENT_LIST_DIR}/platform/windows/inc )
elseif( ${CMAKE_SYSTEM_NAME} STREQUAL "Linux" )
    include_directories( ${CMAKE_CURRENT_LIST_DIR}/platform/linux/inc )
endif()

include( files.cmake )

add_executable(${PROJECT_NAME} ${_GUI_APP_SOURCEFILES})

target_link_libraries(${PROJECT_NAME} PUBLIC OpenGL::GL SDL3::SDL3)