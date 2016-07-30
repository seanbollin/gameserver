// Copyright (c) 2016 Sean Bollin
#include "GameClient.h"

int main(int argc, char* argv[]) {
  GameClient gameClient;
  gameClient.Connect();
  gameClient.SendPacket();
  return 0;
}

