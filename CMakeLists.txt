cmake_minimum_required(VERSION 3.16)
project(raylib_pkg LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(raylib_pkg src/main.cpp src/tetris.cpp src/colors.cpp src/Blocks.cpp src/Position.cpp src/Game.cpp)

# Include directories (adjust if your headers are elsewhere)
target_include_directories(raylib_pkg PRIVATE ${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/lib)

# Link libraries
target_link_libraries(raylib_pkg
    ${CMAKE_SOURCE_DIR}/lib/libraylib.a
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
)