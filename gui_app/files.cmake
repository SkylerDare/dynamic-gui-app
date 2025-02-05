set ( GUI_APP_COMMON_SRC
    common/src/main.cpp
)

set (GUI_APP_COMMON_INC
    common/inc/stdafx.h
)

file(GLOB IMGUI_SOURCE_FILES 
    "${CMAKE_SOURCE_DIR}/3rd_party/imgui/*.cpp"
    "${CMAKE_SOURCE_DIR}/3rd_party/imgui/*.h"
)

set(IMGUI_SOURCE_FILES ${IMGUI_SOURCE_FILES}
    ${CMAKE_SOURCE_DIR}/3rd_party/imgui/backends/imgui_impl_sdl3.h
    ${CMAKE_SOURCE_DIR}/3rd_party/imgui/backends/imgui_impl_sdl3.cpp
    ${CMAKE_SOURCE_DIR}/3rd_party/imgui/backends/imgui_impl_opengl3.h
    ${CMAKE_SOURCE_DIR}/3rd_party/imgui/backends/imgui_impl_opengl3_loader.h
    ${CMAKE_SOURCE_DIR}/3rd_party/imgui/backends/imgui_impl_opengl3.cpp
)

set (SDL_SOURCE_FILES
    ${CMAKE_SOURCE_DIR}/3rd_party/SDL/include/SDL3/SDL.h
    ${CMAKE_SOURCE_DIR}/3rd_party/SDL/include/SDL3/SDL_opengl.h
)

if( ${CMAKE_SYSTEM_NAME} STREQUAL "Windows" )
set( GUI_APP_WIN_SRC 
) 
set( GUI_APP_WIN_INC 
) 
else() 
set( GUI_APP_WIN_SRC )
set( GUI_APP_WIN_INC )
endif()

if( ${CMAKE_SYSTEM_NAME} STREQUAL "Linux" )
set( GUI_APP_LINUX_SRC 
    
)
set( GUI_APP_LINUX_INC 
    
)
else() 
set( GUI_APP_LINUX_SRC )
set( GUI_APP_LINUX_INC )
endif()

set( _GUI_APP_SOURCEFILES
    ${GUI_APP_COMMON_SRC}
    ${GUI_APP_COMMON_INC}
    ${GUI_APP_WIN_SRC}
    ${GUI_APP_WIN_INC}
    ${GUI_APP_LINUX_SRC}
    ${GUI_APP_LINUX_INC}
    ${GUI_APP_TOPLEVEL}
    ${IMGUI_SOURCE_FILES}
    ${SDL_SOURCE_FILES}
    files.cmake
)

source_group( "" FILES ${GUI_APP_TOPLEVEL})
source_group( common/src FILES ${GUI_APP_COMMON_SRC})
source_group( common/inc FILES ${GUI_APP_COMMON_INC})
source_group( platform/windows/src FILES ${GUI_APP_WIN_SRC})
source_group( platform/windows/inc FILES ${GUI_APP_WIN_INC})
source_group( platform/linux/src FILES ${GUI_APP_LINUX_SRC})
source_group( platform/linux/inc FILES ${GUI_APP_LINUX_INC})