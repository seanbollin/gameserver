// Copyright (c) 2016 Sean Bollin
#include "gameserver/GameServer.h"

int main(int argc, char* argv[]) {
  GameServer gameServer;

  while(true) {
    gameServer.Poll();
  }

  return 0;
}
