file(GLOB PROPERTY_PRODUCER_SRC 
    "src/common/src/*"
    "${CMAKE_SOURCE_DIR}/shared/common/src/*"
)

file(GLOB PROPERTY_PRODUCER_INC 
    "src/common/inc/*"
    "${CMAKE_SOURCE_DIR}/shared/common/inc/*"
)

if( ${CMAKE_SYSTEM_NAME} STREQUAL "Windows" )
file(GLOB PROPERTY_PRODUCER_WIN 
    "${CMAKE_SOURCE_DIR}/shared/platform/windows/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/shared/platform/windows/inc/*.h"
)
else() 
set( PROPERTY_PRODUCER_WIN )
endif()

if( ${CMAKE_SYSTEM_NAME} STREQUAL "Linux" )
file(GLOB PROPERTY_PRODUCER_LINUX 
    "${CMAKE_SOURCE_DIR}/shared/platform/linux/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/shared/platform/linux/inc/*.h"
)
else() 
set( PROPERTY_PRODUCER_LINUX )
endif()

set( _PROPERTY_PRODUCER_SOURCEFILES
    ${PROPERTY_PRODUCER_SRC}
    ${PROPERTY_PRODUCER_INC}
    ${PROPERTY_PRODUCER_WIN}
    ${PROPERTY_PRODUCER_LINUX}
    ${PROPERTY_PRODUCER_TOPLEVEL}
    files.cmake
)

source_group( "" FILES ${PROPERTY_PRODUCER_TOPLEVEL})
source_group( property_producer/common/src FILES ${PROPERTY_PRODUCER_SRC})
source_group( property_producer/common/inc FILES ${PROPERTY_PRODUCER_INC})
source_group( property_producer/platform/windows FILES ${PROPERTY_PRODUCER_WIN})
source_group( property_producer/platform/linux FILES ${PROPERTY_PRODUCER_LINUX})