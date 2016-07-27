cmake_minimum_required (VERSION 2.6)
project (GameServer)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set (GameServer_VERSION_MAJOR 0)
set (GameServer_VERSION_MINOR 1)

find_package(ENet REQUIRED)
include_directories(${ENet_INCLUDE_DIRS})
set(LIBS ${LIBS} ${ENet_LIBRARIES})

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/GameServerConfig.h.in"
  "${PROJECT_BINARY_DIR}/GameServerConfig.h"
  )
  
# add the binary tree to the search path for include files
# so that we will find GameServerConfig.h
include_directories("${PROJECT_BINARY_DIR}")
include_directories ("${PROJECT_SOURCE_DIR}/ENet-1.3.13")

add_executable(GameServer main.cpp GameServer.cpp GameServer.h)
target_link_libraries(GameServer ${LIBS})