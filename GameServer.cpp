#include "GameServer.h"
#include "GameServerConfig.h"
#include <enet/enet.h>
#include <iostream>

GameServer::GameServer() {
  std::cout << "GameServer version: " << GameServer_VERSION_MAJOR << "." << GameServer_VERSION_MINOR << "\n";

  if (enet_initialize() != 0) {
    fprintf(stderr, "An error occurred while initializing ENet.\n");
  }

  atexit(enet_deinitialize);

  ENetAddress address;

  // Bind the server to the default localhost.
  // A specific host address can be specified by
  // enet_address_set_host (& address, "x.x.x.x");
  address.host = ENET_HOST_ANY;

  // Bind the server to port 1234.
  address.port = 1234;

  server = enet_host_create(&address, 32, 2, 0, 0);
  if (server == nullptr) {
    fprintf(stderr, "An error occurred while trying to create an ENet server host.\n");
     exit(EXIT_FAILURE);
  }

}

GameServer::~GameServer() {
  enet_host_destroy(server);
}
