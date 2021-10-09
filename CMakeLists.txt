cmake_minimum_required(VERSION 3.20)
project(DifficultMomentsCpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(DifficultMomentsCpp main.cpp)

find_package (Threads REQUIRED)

target_link_libraries(DifficultMomentsCpp
        ${CMAKE_THREAD_LIBS_INIT}
        )