//
// Created by Sean Bollin on 7/28/16.
//

#ifndef GAMESERVER_GAMECLIENT_H
#define GAMESERVER_GAMECLIENT_H
#include "enet/enet.h"

class GameClient {
public:
  GameClient();
  ~GameClient();
private:
  ENetHost* client;

  static const int OUTGOING_CONNECTIONS{1};
  static const int MAX_CHANNELS{2};
  static const int INCOMING_BANDWIDTH{57600 / 8};
  static const int OUTGOING_BANDWIDTH{14400 / 8};
};


#endif //GAMESERVER_GAMECLIENT_H
