#ifndef GAMESERVER_CAPP_H
#define GAMESERVER_CAPP_H

#include <SDL.h>
#include "Network.h"
#include "spdlog/spdlog.h"

class Client {
public:
  Client(Network* network);
  virtual ~Client();
  int Execute();
  bool Init();
  void Loop();
  void Render();
  void Cleanup();
private:
  void OnEvent(SDL_Event* Event);

  bool running{false};
  SDL_Window* window{nullptr};
  SDL_Surface* surface{nullptr};

  Network* network;

  static const int WIDTH{640};
  static const int HEIGHT{480};

  std::shared_ptr<spdlog::logger> console{spdlog::stdout_logger_st("GameServer", true)};
};

#endif //GAMESERVER_CAPP_H
