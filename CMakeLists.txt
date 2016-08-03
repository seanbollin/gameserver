cmake_minimum_required(VERSION 3.1)
project(GameServer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(ENet REQUIRED)

include_directories(${ENet_INCLUDE_DIRS})

add_subdirectory(client)
add_subdirectory(gameserver)
add_subdirectory(gameserver_tests)