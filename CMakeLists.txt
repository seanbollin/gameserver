cmake_minimum_required(VERSION 3.1)
project(GameServer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(GameServer_VERSION_MAJOR 0)
set(GameServer_VERSION_MINOR 1)

find_package(ENet REQUIRED)

include_directories(${ENet_INCLUDE_DIRS} gameserver/include)

add_subdirectory(client)
add_subdirectory(client_tests)
add_subdirectory(gameserver)
add_subdirectory(gameserver_tests)

add_executable(gs main.cpp)

target_link_libraries(gs gameserver ${ENet_LIBRARIES})