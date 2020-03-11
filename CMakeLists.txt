cmake_minimum_required(VERSION 3.15)
project(rodeo_race)

set(CMAKE_CXX_STANDARD 17)

add_executable(custom_mutex custom_mutex.cpp)
target_link_libraries(custom_mutex pthread)