#ifndef CLIENT_VISUALS_DOT_H_
#define CLIENT_VISUALS_DOT_H_

#include <SDL_events.h>

class Dot {
 public:
  static const int DOT_WIDTH = 20;
  static const int DOT_HEIGHT = 20;

  static const int DOT_VEL = 10;

  void handleEvent(const SDL_Event& e);
  void move();
  void render();

  int getVelX() const;
  int getVelY() const;

 private:
  int posX = 0;
  int posY = 0;

  int velX = 0;
  int velY = 0;
};

#endif  // CLIENT_VISUALS_DOT_H_
