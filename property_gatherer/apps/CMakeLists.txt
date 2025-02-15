cmake_minimum_required( VERSION 3.29 )
set(CMAKE_CXX_STANDARD 17 )
set(CMAKE_CXX_STANDARD_REQUIRED True )

project( property_gatherer )

add_subdirectory(property_consumer)
add_subdirectory(property_producer)