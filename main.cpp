#include "gameserver/GameServer.h"
#include "spdlog/spdlog.h"
#include <sstream>

int main(int argc, char* argv[]) {
  auto console = spdlog::stdout_logger_st("main", true);

  if (argc < 2) {
    console->error("usage: {} <frameRate>", argv[0]);
  }

  std::istringstream ss(argv[1]);
  int frameRate;
  ss >> frameRate;

  GameServer gameServer{frameRate};
  gameServer.Start();
}
