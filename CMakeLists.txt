cmake_minimum_required(VERSION 3.20)
project(DifficultMomentsCpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(DifficultMomentsCpp main.cpp stdfax.h Person.h Person.cpp
        PhoneNumber.h PhoneNumber.cpp PhoneBook.h PhoneBook.cpp)
