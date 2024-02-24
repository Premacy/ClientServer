cmake_minimum_required(VERSION 2.6)
project(Client)

include_directories("Headers")
include_directories("Src")

set(HEADERS Headers/Client.h Headers/TimerFunction.h)
set(MAIN_PROJECT_SRC_LIST Src/Client.cpp  Src/ClientTest.cpp Src/TimerFunction.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")

add_executable(Client ${MAIN_PROJECT_SRC_LIST})
