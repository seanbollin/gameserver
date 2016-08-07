#include "GameServer.h"
#include "GameServerConfig.h"

GameServer::GameServer(int frameRate) {
  this->frameRate = frameRate;

  console->info("Game version: {}.{} frameRate: {}",
                GameServer_VERSION_MAJOR, GameServer_VERSION_MINOR, frameRate);

  if (enet_initialize() != 0) {
    console->error("An error occurred while initializing ENet.");
  }

  atexit(enet_deinitialize);

  ENetAddress address;

  address.host = ENET_HOST_ANY;

  address.port = PORT;

  server = enet_host_create(&address, MAX_CONNECTIONS, MAX_CHANNELS, INCOMING_BANDWIDTH, OUTGOING_BANDWIDTH);
  if (server == nullptr) {
    console->error("An error occurred while trying to create an ENet server host.");
    exit(EXIT_FAILURE);
  }
}

void GameServer::Start() {
  using clock = std::chrono::high_resolution_clock;
  using ms = std::chrono::milliseconds;

  while(true) {
    auto time_start = clock::now();

    Poll();

    auto loop_time = clock::now() - time_start;
    std::this_thread::sleep_for(ms(frameRate) - loop_time);
    // std::chrono::duration<double> diff = clock::now() - time_start;
  }
}

void GameServer::Poll() {
  ENetEvent event;

  while (enet_host_service(server, &event, POLL_TIMEOUT) > 0) {
    switch (event.type) {
      case ENET_EVENT_TYPE_CONNECT:
        console->info("A new client connected from {}:{}.",
                      event.peer->address.host, event.peer -> address.port);
        // event.peer->data = (void*) "Client information";
        break;
      case ENET_EVENT_TYPE_RECEIVE:
        console->info("A packet of length {} was received from {} on channel {}.",
                      event.packet->dataLength, event.peer->data, event.channelID);
        enet_packet_destroy(event.packet);
        break;

      case ENET_EVENT_TYPE_DISCONNECT:
        console->info("{} disconnected.", event.peer->data);
        // Reset the peer's client information.
        event.peer->data = nullptr;
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
