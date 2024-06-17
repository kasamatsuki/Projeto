cmake_minimum_required(VERSION 3.21)
project(FirstProjectTester)
set(CMAKE_CXX_STANDARD 14)
set(PROJECT_HEADERS_DIR ../FirstProject/headers)
set(PROJECT_SOURCES_DIR ../FirstProject/sources)
include_directories(${PROJECT_HEADERS_DIR})
include_directories(${PROJECT_SOURCES_DIR})
set(GOOGLE_TEST_LIB ../Projeto2.0/googleTestLib/googletest-main)
set(GOOGLE_TEST_LIB_INCLUDE ${GOOGLE_TEST_LIB}/googletest/include)
add_subdirectory(${GOOGLE_TEST_LIB})
include_directories(${GOOGLE_TEST_LIB_INCLUDE})
set(SOURCE_FILES
        main.cpp
        ${PROJECT_HEADERS_DIR}/factorial.h
        ${PROJECT_SOURCES_DIR}/factorial.cpp
)
add_executable(FirstProjectTester ${SOURCE_FILES})
target_link_libraries(FirstProjectTester gtest gtest_main)
