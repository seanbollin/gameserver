project(client_tests)

include_directories(../client/visuals)
include(${CMAKE_SOURCE_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

if (NOT TARGET gtest)
add_subdirectory("../gameserver_tests/lib/gtest-1.7.0" "${CMAKE_CURRENT_BINARY_DIR}/client_tests_build")
endif()

add_subdirectory(basic_tests)