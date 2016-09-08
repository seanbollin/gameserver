include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(run_client_tests basic_check.cpp)

target_link_libraries(run_client_tests gtest gtest_main)
target_link_libraries(run_client_tests client)