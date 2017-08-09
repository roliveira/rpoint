cmake_minimum_required(VERSION 3.2)
PROJECT(rpoint)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")

include_directories(${PROJECT_SOURCE_DIR}/include)

set(HEADERS
    include/rpoint.h
	include/rpointvector.h
    include/rdistance.h
)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE include/)

# Includes external projects in the main project:
set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/external)

# Includes Catch in the project:
add_subdirectory(${EXT_PROJECTS_DIR}/catch)
include_directories(${CATCH_INCLUDE_DIR} ${COMMON_INCLUDES})
enable_testing(true)  # Enables unit-testing.

# Prepare "Catch" library for other executables
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

# Tests
file(GLOB_RECURSE TEST_SRC_FILES RELATIVE
	${PROJECT_SOURCE_DIR}
	tests/*.cpp
)

set(PROJECT_TEST_NAME ${PROJECT_NAME}_test)
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES} ${HEADERS})
add_test(NAME ${PROJECT_TEST_NAME} COMMAND ${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
