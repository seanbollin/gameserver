#ifndef CLIENT_GAMECLIENT_H_
#define CLIENT_GAMECLIENT_H_
#include <string>
#include "enet/enet.h"

class GameClient {
 public:
  GameClient();
  void Connect();
  void SendPacket();
  virtual ~GameClient();
 private:
  const std::string serverUrl = "localhost";
  static const int PORT = 1234;

  ENetHost* client{nullptr};
  ENetPeer* peer{nullptr};
  ENetAddress address{ENET_HOST_ANY, ENET_PORT_ANY};

  static const int CONNECT_TIMEOUT = 5000;
  static const int OUTGOING_CONNECTIONS{1};
  static const int MAX_CHANNELS{2};
  static const int INCOMING_BANDWIDTH{57600 / 8};
  static const int OUTGOING_BANDWIDTH{14400 / 8};
};


#endif  // CLIENT_GAMECLIENT_H_
