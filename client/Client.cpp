#include "Client.h"

Client::Client(Network* network) : network(network) {}

int Client::Execute() {
  spdlog::set_level(spdlog::level::debug);

  if(Init() == false) {
    return -1;
  }

  SDL_Event event;

  while(!quit) {
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
    }
  }

  return true;
}

void Client::OnEvent(SDL_Event* event) {
  console->debug("Received SDL_Event type {}", event->type);
  if (event->type == SDL_QUIT) quit = true;
}

void Client::Loop() { }

void Client::Render() { }

Client::~Client() {
  SDL_DestroyWindow(window);
  SDL_Quit();
}
