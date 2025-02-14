cmake_minimum_required(VERSION 3.29)
project(_Programming_Basics_CPP_11_2)

set(CMAKE_CXX_STANDARD 20)

add_library(leave_lib SHARED lib/leave_lib.cpp)

target_include_directories(leave_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_executable(_Programming_Basics_CPP_11_2 main.cpp)

target_link_libraries(_Programming_Basics_CPP_11_2 leave_lib)
