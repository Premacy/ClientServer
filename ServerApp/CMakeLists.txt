cmake_minimum_required(VERSION 2.6)
project(Server)

include_directories("Headers")
include_directories("Src")

set(HEADERS Headers/Server.h Headers/Logger.h)
set(MAIN_PROJECT_SRC_LIST Src/Server.cpp  Src/Logger.cpp Src/ServerTest.cpp)

add_executable(Server ${MAIN_PROJECT_SRC_LIST})
