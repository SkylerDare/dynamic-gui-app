file(GLOB PROPERTY_CONSUMER_SRC 
    "src/common/src/*"
    "${CMAKE_SOURCE_DIR}/shared/common/src/*"
)

file(GLOB PROPERTY_CONSUMER_INC 
    "src/common/inc/*"
    "${CMAKE_SOURCE_DIR}/shared/common/inc/*"
)

if( ${CMAKE_SYSTEM_NAME} STREQUAL "Windows" )
file(GLOB PROPERTY_CONSUMER_WIN 
    "${CMAKE_SOURCE_DIR}/shared/platform/windows/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/shared/platform/windows/inc/*.h"
)
else() 
set( PROPERTY_CONSUMER_WIN )
endif()

if( ${CMAKE_SYSTEM_NAME} STREQUAL "Linux" )
file(GLOB PROPERTY_CONSUMER_LINUX 
    "${CMAKE_SOURCE_DIR}/shared/platform/linux/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/shared/platform/linux/inc/*.h"
)
else() 
set( PROPERTY_CONSUMER_LINUX )
endif()

set( _PROPERTY_CONSUMER_SOURCEFILES
    ${PROPERTY_CONSUMER_SRC}
    ${PROPERTY_CONSUMER_INC}
    ${PROPERTY_CONSUMER_WIN}
    ${PROPERTY_CONSUMER_LINUX}
    ${PROPERTY_CONSUMER_TOPLEVEL}
    files.cmake
)

source_group( "" FILES ${PROPERTY_CONSUMER_TOPLEVEL})
source_group( property_consumer/common/src FILES ${PROPERTY_CONSUMER_SRC})
source_group( property_consumer/common/inc FILES ${PROPERTY_CONSUMER_INC})
source_group( property_consumer/platform/windows FILES ${PROPERTY_CONSUMER_WIN})
source_group( property_consumer/platform/linux FILES ${PROPERTY_CONSUMER_LINUX})