#ifndef GAMESERVER_GAMESERVER_H
#define GAMESERVER_GAMESERVER_H


#include <enet/enet.h>

class GameServer {
public:
  GameServer();
  ~GameServer();
private:
  static const int PORT{1234};
  static const int MAX_CONNECTIONS{32};
  static const int MAX_CHANNELS{2};
  static const int INCOMING_BANDWIDTH{0};
  static const int OUTGOING_BANDWIDTH{0};

  ENetHost* server{nullptr};
};


#endif //GAMESERVER_GAMESERVER_H
