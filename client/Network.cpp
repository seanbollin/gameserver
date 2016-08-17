#include <cstdio>
#include <iostream>
#include "Network.h"
#include <cstring>

Network::Network() {
  client = enet_host_create(
          nullptr,  // client specified by giving no host to bind to
          OUTGOING_CONNECTIONS,
          MAX_CHANNELS,
          INCOMING_BANDWIDTH,
          OUTGOING_BANDWIDTH);

  if (client == nullptr) {
    fprintf(stderr, "An error occurred while trying to create an ENet client host.\n");
    exit(EXIT_FAILURE);
  }
}

void Network::Connect() {
  ENetEvent event;

  enet_address_set_host(&address, serverUrl.c_str());
  address.port = PORT;

  // Initiate the connection, allocating the two channels 0 and 1.
  peer = enet_host_connect(client, &address, 2, 0);
  if (peer == nullptr) {
    fprintf(stderr, "No available peers for initiating an ENet connection.\n");
    exit(EXIT_FAILURE);
  }

  if (enet_host_service(client, &event, CONNECT_TIMEOUT) > 0 && event.type == ENET_EVENT_TYPE_CONNECT) {
    std::cout << "Connection to " << serverUrl << ":" << PORT << " succeeded";
  } else {
    enet_peer_reset(peer);
    std::cout << "Connection to " << serverUrl << ":" << PORT << " failed";
  }
}

void Network::SendPacket() {
  // packet deallocated with enet_peer_send
  ENetPacket* packet = enet_packet_create("packet", strlen("packet") + 1, ENET_PACKET_FLAG_RELIABLE);

  // Send the packet to the peer over channel id 0.
  enet_peer_send(peer, 0, packet);

  // One could just use enet_host_service() instead.
  enet_host_flush(client);
}

Network::~Network() {
  enet_host_destroy(client);
}
