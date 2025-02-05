# dynamic-gui-app
CS 4910 Senior Project - Dynamic GUI Application

## Build instructions
1. Clone the git repo i.e "git clone https://github.com/acichy2281/dynamic-gui-app.git"
2. Create a build directory at the top level of the project. i.e "cd Path/to/dynamic-gui-app", "mkdir build"
3. In the build directory enter "cmake .." 
4. Build the project from the build directory "cmake --build ." or from the top level "cmake --build build"

## Dependencies 
Application uses OpenGL & SDL for the backend. OpenGL is built in with Graphic Drivers for AMD, NVIDIA, and Intel. 

CMake 3.29 and C++17 are required

## 3rd Party Repositories included 
SDL - v3.2.0
IMGUI - v1.91.7
nlohmann json - v3.11.1

### Windows
C/C++ Build tools
Visual Studio 2022 Recommend
Visual Studio .NET Core C/C++ build tools Recommended

### Linux
Requires X11, Wayland, OpenGL

The following command should get all required dependencies. 
<pre> sudo apt-get install libwayland-dev gnome-desktop-testing libasound2-dev libpulse-dev \
libaudio-dev libjack-dev libsndio-dev libx11-dev libxext-dev libxrandr-dev libxcursor-dev \
libxfixes-dev libxi-dev libxss-dev libxkbcommon-dev libdrm-dev libgbm-dev libgl1-mesa-dev \
libgles2-mesa-dev libegl1-mesa-dev libdbus-1-dev libibus-1.0-dev libudev-dev fcitx-libs-dev </pre>

### MacOS
Not sure, cannot build for this platform. 
