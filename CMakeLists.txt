cmake_minimum_required(VERSION 3.10)
project(tank)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
find_library(SDL2_GFX_LIBRARIES NAMES SDL2_gfx)

include_directories(${SDL2_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include/)

file(GLOB SOURCES_DIR "src/*.cpp")

add_executable(tank main.cpp ${SOURCES_DIR})

target_link_libraries(tank ${SDL2_GFX_LIBRARIES})
target_link_libraries(tank ${SDL2_LIBRARIES})
