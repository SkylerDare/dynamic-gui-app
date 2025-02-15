cmake_minimum_required( VERSION 3.29 )
set(CMAKE_CXX_STANDARD 17 )
set(CMAKE_CXX_STANDARD_REQUIRED True )

project( property_gatherer_library )

# Define the library
include(files.cmake)
add_library(${PROJECT_NAME} SHARED)

# Include the headers
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

# Add the source files
target_sources(${PROJECT_NAME} PUBLIC ${PROPERTY_GATHERER_LIBRARY_SRC})