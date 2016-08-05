project(gameserver)

configure_file(
        "GameServerConfig.h.in"
        "${PROJECT_BINARY_DIR}/GameServerConfig.h"
)

add_library(gameserver STATIC GameServer.cpp)