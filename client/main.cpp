#include "Network.h"
#include "Client.h"

int main() {
  Network* network = new Network();
  Client client{network};

  return client.Execute();
}

