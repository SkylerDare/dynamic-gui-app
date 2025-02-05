file(GLOB GUI_APP_COMMON_SRC 
    "src/common/src/*"
    "${CMAKE_SOURCE_DIR}/shared/common/src/*.cpp"
)

file(GLOB GUI_APP_COMMON_INC 
    "src/common/inc/*"
    "${CMAKE_SOURCE_DIR}/shared/common/inc/*"
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
file(GLOB GUI_APP_WIN 
    "${CMAKE_SOURCE_DIR}/shared/platform/windows/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/shared/platform/windows/inc/*.h"
)
else() 
set( GUI_APP_WIN )
endif()

if( ${CMAKE_SYSTEM_NAME} STREQUAL "Linux" )
file(GLOB GUI_APP_LINUX 
    "${CMAKE_SOURCE_DIR}/shared/platform/linux/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/shared/platform/linux/inc/*.h"
)
else() 
set( GUI_APP_LINUX )
endif()

set( _GUI_APP_SOURCEFILES
    ${GUI_APP_COMMON_SRC}
    ${GUI_APP_COMMON_INC}
    ${GUI_APP_WIN}
    ${GUI_APP_LINUX}
    ${GUI_APP_TOPLEVEL}
    ${IMGUI_SOURCE_FILES}
    ${SDL_SOURCE_FILES}
    files.cmake
)

source_group( "" FILES ${GUI_APP_TOPLEVEL})
source_group( gui_app/common/src FILES ${GUI_APP_COMMON_SRC})
source_group( gui_app/common/inc FILES ${GUI_APP_COMMON_INC})
source_group( gui_app/platform/windows FILES ${GUI_APP_WIN})
source_group( gui_app/platform/linux FILES ${GUI_APP_LINUX})
source_group( imgui FILES ${IMGUI_SOURCE_FILES})
source_group( sdl FILES ${SDL_SOURCE_FILES})