cmake_minimum_required(VERSION 3.13)
project(Activity_Tracker)

set(CMAKE_CXX_STANDARD 11)

add_executable(Activity_Tracker main.cpp Task.cpp Task.h Project.cpp Project.h)