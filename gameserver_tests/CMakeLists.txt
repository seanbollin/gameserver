project(gameserver_tests)

if (NOT TARGET gtest)
add_subdirectory(lib/gtest-1.7.0)
endif()

add_subdirectory(basic_tests)