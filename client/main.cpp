#include "GameClient.h"

int main() {
  GameClient gameClient;
  gameClient.Connect();
  gameClient.SendPacket();
  return 0;
}

