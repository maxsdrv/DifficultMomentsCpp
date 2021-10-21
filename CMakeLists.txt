cmake_minimum_required(VERSION 3.20)
project(DifficultMomentsCpp)

set(CMAKE_CXX_STANDARD 20)

find_package(Threads)

add_subdirectory(googletest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(DifficultMomentsCpp main.cpp Person.h Person.cpp
PhoneBook.cpp PhoneBook.h PhoneNumber.cpp PhoneNumber.h stdfax.h UnitTest.h)

target_link_libraries(DifficultMomentsCpp gtest gtest_main)
target_link_libraries(DifficultMomentsCpp ${CMAKE_THREAD_LIBS_INIT})
add_test(DifficultMomentsCpp runUnitTests)