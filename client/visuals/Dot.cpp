#include <iostream>
#include "Dot.h"

void Dot::handleEvent(SDL_Event& e) {

  if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
    std::cout << "here we go: " << e.type << " " << e.key.keysym.sym << std::endl;
    switch (e.key.keysym.sym) {
      case SDLK_UP:
        velY -= DOT_VEL;
        break;
      case SDLK_DOWN:
        velY += DOT_VEL;
        break;
      case SDLK_LEFT:
        velX -= DOT_VEL;
        break;
      case SDLK_RIGHT:
        velX += DOT_VEL;
        break;
    }
  }
}

int Dot::getVelX() const {
  return velX;
}

int Dot::getVelY() const {
  return velY;
}
