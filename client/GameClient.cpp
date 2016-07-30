//
// Created by Sean Bollin on 7/28/16.
//

#include <cstdio>
#include <iostream>
#include "GameClient.h"

GameClient::GameClient() {
  std::cout << "Constructing game client\n";

  client = enet_host_create(
          nullptr, // client specified by giving no host to bind to
          OUTGOING_CONNECTIONS,
          MAX_CHANNELS,
          INCOMING_BANDWIDTH,
          OUTGOING_BANDWIDTH
  );

  if (client == nullptr) {
    fprintf(stderr, "An error occurred while trying to create an ENet client host.\n");
    exit(EXIT_FAILURE);
  }
}

void GameClient::Connect() {
  ENetAddress address;
  ENetEvent event;

  // Connect to some.server.net:1234.
  enet_address_set_host(&address, "localhost");
  address.port = 1234;

  // Initiate the connection, allocating the two channels 0 and 1.
  peer = enet_host_connect(client, &address, 2, 0);
  if (peer == nullptr) {
    fprintf(stderr, "No available peers for initiating an ENet connection.\n");
    exit(EXIT_FAILURE);
  }

  // Wait up to 5 seconds for the connection attempt to succeed.
  if (enet_host_service(client, &event, 5000) > 0 && event.type == ENET_EVENT_TYPE_CONNECT) {
    puts("Connection to some.server.net:1234 succeeded.");
  } else {
    // Either the 5 seconds are up or a disconnect event was
    // received. Reset the peer in the event the 5 seconds
    // had run out without any significant event.
    enet_peer_reset(peer);
    puts("Connection to some.server.net:1234 failed.");
  }
}

void GameClient::SendPacket() {
  // packet deallocated with enet_peer_send
  ENetPacket* packet = enet_packet_create("packet", strlen("packet") + 1, ENET_PACKET_FLAG_RELIABLE);

  // Send the packet to the peer over channel id 0.
  enet_peer_send(peer, 0, packet);

  // One could just use enet_host_service() instead.
  enet_host_flush(client);
}

GameClient::~GameClient() {
  enet_host_destroy(client);
}