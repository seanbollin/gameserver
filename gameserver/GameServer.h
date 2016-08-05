#ifndef GAMESERVER_GAMESERVER_H_
#define GAMESERVER_GAMESERVER_H_

#include <enet/enet.h>
#include <memory>
#include "spdlog/spdlog.h"

class GameServer {
 public:
  explicit GameServer(int);
  void Start();
  virtual ~GameServer();
 private:
  static const int PORT{1234};
  static const int MAX_CONNECTIONS{32};
  static const int MAX_CHANNELS{2};
  static const int INCOMING_BANDWIDTH{0};
  static const int OUTGOING_BANDWIDTH{0};
  static const int POLL_TIMEOUT{0};

  std::shared_ptr<spdlog::logger> console{spdlog::stdout_logger_st("GameServer", true)};

  ENetHost* server{nullptr};

  int frameRate{0};

  void Poll();
};


#endif  // GAMESERVER_GAMESERVER_H_
