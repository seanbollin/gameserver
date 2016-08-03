project(gameserver)

set(GameServer_VERSION_MAJOR 0)
set(GameServer_VERSION_MINOR 1)

set(SOURCES main.cpp GameServer.cpp GameServer.h GameServerConfig.h)

configure_file(
        "GameServerConfig.h.in"
        "${PROJECT_BINARY_DIR}/GameServerConfig.h"
)

include_directories(${gameserver_SOURCE_DIR}/include)

add_executable(gs ${SOURCES})

target_link_libraries(gs ${ENet_LIBRARIES})