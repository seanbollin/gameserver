#include "GameServer.h"
#include "GameServerConfig.h"
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
  address.port = PORT;

  server = enet_host_create(&address, MAX_CONNECTIONS, MAX_CHANNELS, INCOMING_BANDWIDTH, OUTGOING_BANDWIDTH);
  if (server == nullptr) {
    fprintf(stderr, "An error occurred while trying to create an ENet server host.\n");
     exit(EXIT_FAILURE);
  }
}

void GameServer::Poll() {
  ENetEvent event;

  while (enet_host_service(server, &event, POLL_TIMEOUT) > 0) {
    switch (event.type) {
      case ENET_EVENT_TYPE_CONNECT:
        printf("A new client connected from %x:%u.\n",
                event.peer -> address.host,
                event.peer -> address.port);
        // Store any relevant client information here.
        // event.peer->data = (void*) "Client information";
        break;
      case ENET_EVENT_TYPE_RECEIVE:
        printf("A packet of length %zu containing %s was received from %s on channel %u.\n",
                event.packet->dataLength,
                event.packet->data,
                event.peer->data,
                event.channelID);
        // Clean up the packet now that we're done using it.
        enet_packet_destroy(event.packet);
        break;

      case ENET_EVENT_TYPE_DISCONNECT:
        printf("%s disconnected.\n", event.peer -> data);
        // Reset the peer's client information.
        event.peer -> data = NULL;
        break;

      case ENET_EVENT_TYPE_NONE:
        // remove compiler warning, do nothing
        break;
    }
  }
}

GameServer::~GameServer() {
  enet_host_destroy(server);
}
