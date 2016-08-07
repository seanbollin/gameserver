#include "Client.h"

Client::Client(Network* network) : network(network) {}

int Client::Execute() {
  if(Init() == false) {
    return -1;
  }

  SDL_Event event;

  while(running) {
    while(SDL_PollEvent(&event)) {
      OnEvent(&event);
    }

    Loop();
    Render();
  }

  return 0;
}

bool Client::Init() {
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    console->error("SDL could not initialize! SDL_Error: {}", SDL_GetError());
  } else {
    window = SDL_CreateWindow("SDL Tutorial",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              WIDTH,
                              HEIGHT,
                              SDL_WINDOW_SHOWN);
    if (window == nullptr) {
      console->error("Window could not be created! SDL_Error: {}", SDL_GetError());
    } else {
      surface = SDL_GetWindowSurface(window);

      SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));

      SDL_UpdateWindowSurface(window);

      network->Connect();
      network->SendPacket();

      SDL_Delay(2000);
    }
  }

  return true;
}

void Client::OnEvent(SDL_Event* event) {

}

void Client::Loop() { }

void Client::Render() { }

Client::~Client() {
  SDL_DestroyWindow(window);
  SDL_Quit();
}
