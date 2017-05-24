cmake_minimum_required(VERSION 3.2)
PROJECT(point)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(HEADERS
    include/rpoint.h
    include/rdistance.h
)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(PROJECT_TEST_NAME ${PROJECT_NAME}_test)
file(GLOB_RECURSE TEST_SRC_FILES RELATIVE
	${PROJECT_SOURCE_DIR}
	tests/*.cpp
)

add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES} ${HEADERS})
target_link_libraries(${PROJECT_TEST_NAME} ${GTEST_BOTH_LIBRARIES})
add_test(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})

