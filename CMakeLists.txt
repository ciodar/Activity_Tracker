cmake_minimum_required(VERSION 3.13)
project(Activity_Tracker)

set(CMAKE_CXX_STANDARD 11)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)
# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)

add_executable(Activity_Tracker main.cpp Task.cpp Task.h Project.cpp Project.h Subject.h Observer.h Model.cpp Model.h Controller.cpp Controller.h View.cpp View.h MainWindow.ui ViewWindow.cpp ViewWindow.h)
# Use the Widgets module from Qt 5.
target_link_libraries(Activity_Tracker Qt5::Widgets)
