project(gameserver)

configure_file(
        "GameServerConfig.h.in"
        "${PROJECT_BINARY_DIR}/GameServerConfig.h"
)

include_directories(${gameserver_SOURCE_DIR}/include)

set(SOURCES GameServer.cpp GameServer.h GameServerConfig.h)

add_library(gameserver STATIC ${SOURCES})