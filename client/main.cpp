// Copyright (c) 2016 Sean Bollin
#include "GameClient.h"

int main() {
  GameClient gameClient;
  gameClient.Connect();
  gameClient.SendPacket();
  return 0;
}

