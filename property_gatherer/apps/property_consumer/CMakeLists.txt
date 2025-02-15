cmake_minimum_required( VERSION 3.29 )
set(CMAKE_CXX_STANDARD 17 )
set(CMAKE_CXX_STANDARD_REQUIRED True )

project( property_consumer )

# 3rd party includes 
# set(JSON_BuildTests OFF CACHE INTERNAL "")
# set(NLOHMANN_JSON_SOURCE_DIR "${CMAKE_SOURCE_DIR}/3rd_party/nlohmann_json")
# set(NLOHMANN_JSON_BINARY_DIR "${CMAKE_BINARY_DIR}/bin/nlohmann_json")
# add_subdirectory(${NLOHMANN_JSON_SOURCE_DIR} ${NLOHMANN_JSON_BINARY_DIR})

# Project includes 
include_directories( ${CMAKE_CURRENT_LIST_DIR}/src/common/inc )
include_directories( ${CMAKE_SOURCE_DIR}/shared/common/inc )
if( ${CMAKE_SYSTEM_NAME} STREQUAL "Windows" )
    include_directories( ${CMAKE_CURRENT_LIST_DIR}/src/platform/windows/inc )
    include_directories( ${CMAKE_SOURCE_DIR}/shared/platform/windows/inc )
elseif( ${CMAKE_SYSTEM_NAME} STREQUAL "Linux" )
    include_directories( ${CMAKE_CURRENT_LIST_DIR}/src/platform/linux/inc )
    include_directories( ${CMAKE_SOURCE_DIR}/shared/platform/linux/inc )
endif()

include( files.cmake )

add_executable(${PROJECT_NAME} ${_PROPERTY_CONSUMER_SOURCEFILES})

target_link_libraries(${PROJECT_NAME} property_gatherer_library nlohmann_json::nlohmann_json)