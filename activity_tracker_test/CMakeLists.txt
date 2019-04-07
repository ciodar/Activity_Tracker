cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp ProjectFixture.cpp TaskFixture.cpp MVCFixture.cpp)
add_executable(runActivityTrackerTests ${TEST_SOURCE_FILES})
target_link_libraries(runActivityTrackerTests gtest gtest_main Qt5::Widgets core)
