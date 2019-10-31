cmake_minimum_required(VERSION 3.3.2)
project( hpx_thread_testing CXX)
find_package(HPX REQUIRED)
add_hpx_executable( hpx_thread_tests SOURCES source/cpp-hpx-thread-testing.cpp)
