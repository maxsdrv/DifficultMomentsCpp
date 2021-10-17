cmake_minimum_required(VERSION 3.20)
project(DifficultMomentsCpp)

set(CMAKE_CXX_STANDARD 20)

find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS Students.proto)
add_executable(DifficultMomentsCpp  main.cpp ${PROTO_SRCS} ${PROTO_HDRS} IRepository.h IMethods.h StudentsGroup.cpp StudentsGroup.h Student.cpp Student.h FullName.cpp FullName.h)
target_link_libraries(DifficultMomentsCpp ${Protobuf_LIBRARIES})
