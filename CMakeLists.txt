cmake_minimum_required(VERSION 3.20)
project(easyCurses C)

set(CMAKE_C_STANDARD 99)


find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(easyCurses main.c easyCurses.h easyCurses.c)
target_link_libraries(easyCurses ${CURSES_LIBRARIES})