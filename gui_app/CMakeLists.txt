cmake_minimum_required( VERSION 3.29 )
set(CMAKE_CXX_STANDARD 17 )
set(CMAKE_CXX_STANDARD_REQUIRED True )

project( gui_app )

find_package(OpenGL REQUIRED)

# 3rd party includes 
set(JSON_BuildTests OFF CACHE INTERNAL "")
set(SDL_SOURCE_DIR "${CMAKE_SOURCE_DIR}/3rd_party/SDL")
set(SDL_BINARY_DIR "${CMAKE_BINARY_DIR}/bin/SDL")
add_subdirectory(${SDL_SOURCE_DIR} ${SDL_BINARY_DIR})
set(NLOHMANN_JSON_SOURCE_DIR "${CMAKE_SOURCE_DIR}/3rd_party/nlohmann_json")
set(NLOHMANN_JSON_BINARY_DIR "${CMAKE_BINARY_DIR}/bin/nlohmann_json")
add_subdirectory(${NLOHMANN_JSON_SOURCE_DIR} ${NLOHMANN_JSON_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR}/3rd_party/imgui)

# Project includes 
include_directories( ${CMAKE_CURRENT_LIST_DIR}/src/common/inc )
if( ${CMAKE_SYSTEM_NAME} STREQUAL "Windows" )
    include_directories( ${CMAKE_CURRENT_LIST_DIR}/src/platform/windows/inc )
elseif( ${CMAKE_SYSTEM_NAME} STREQUAL "Linux" )
    include_directories( ${CMAKE_CURRENT_LIST_DIR}/src/platform/linux/inc )
endif()

include( files.cmake )

add_executable(${PROJECT_NAME} ${_GUI_APP_SOURCEFILES})

target_link_libraries(${PROJECT_NAME} PUBLIC OpenGL::GL SDL3::SDL3)