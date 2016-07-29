//
// Created by Sean Bollin on 7/28/16.
//

#include <cstdio>
#include <iostream>
#include "GameClient.h"

GameClient::GameClient() {
  std::cout << "Constructing game client\n";

  client = enet_host_create(
          nullptr,
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

GameClient::~GameClient() {
  enet_host_destroy(client);
}