project(gameserver)

set(HEADER_FILES
        GameServer.h
        )

set(SOURCE_FILES
        GameServer.cpp
        )

add_library(gameserver STATIC ${SOURCE_FILES} ${HEADER_FILES})