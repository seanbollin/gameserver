#ifndef GAMESERVER_GAMESERVER_H
#define GAMESERVER_GAMESERVER_H


#include <enet/enet.h>

class GameServer {
public:
  GameServer();
  ~GameServer();
private:
  ENetHost* server{nullptr};
};


#endif //GAMESERVER_GAMESERVER_H
