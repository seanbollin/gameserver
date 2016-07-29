cmake_minimum_required(VERSION 3.1)
project(GameServer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(SOURCE_FILES main.cpp)

set(GameServer_VERSION_MAJOR 0)
set(GameServer_VERSION_MINOR 1)

configure_file(
  "gameserver/GameServerConfig.h.in"
  "${PROJECT_BINARY_DIR}/GameServerConfig.h"
  )

find_package(ENet REQUIRED)

include_directories(gameserver)
include_directories(${ENet_INCLUDE_DIRS})

add_executable(gs ${SOURCE_FILES})

add_subdirectory(gameserver)
add_subdirectory(gameserver_tests)

target_link_libraries(gs gameserver ${ENet_LIBRARIES})