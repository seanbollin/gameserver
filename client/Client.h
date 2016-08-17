#ifndef CLIENT_CLIENT_H_
#define CLIENT_CLIENT_H_

#include <SDL.h>
#include "Network.h"
#include "spdlog/spdlog.h"

class Client {
 public:
  explicit Client(Network* network);
  virtual ~Client();
  int Execute();
  bool Init();
  void Loop();
  void Render();
  void Cleanup();
 private:
  void OnEvent(SDL_Event* Event);

  bool quit{false};
  SDL_Window* window{nullptr};
  SDL_Surface* surface{nullptr};

  Network* network;

  static const int WIDTH{640};
  static const int HEIGHT{480};

  std::shared_ptr<spdlog::logger> console{spdlog::stdout_logger_st("GameServer", true)};
};

#endif  // CLIENT_CLIENT_H_
