#include "gameserver/GameServer.h"

int main() {
  GameServer gameServer;

  bool gameLoop = true;

  while(gameLoop) {
    gameServer.Poll();
  }

  return 0;
}
