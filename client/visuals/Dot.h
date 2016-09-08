#ifndef GAMESERVER_DOT_H
#define GAMESERVER_DOT_H

#include <SDL_events.h>

class Dot {
public:
  static const int DOT_WIDTH = 20;
  static const int DOT_HEIGHT = 20;

  static const int DOT_VEL = 10;

  void handleEvent(SDL_Event& e);
  void move();
  void render();

private:
  int posX = 0;
  int posY = 0;

  int velX = 0;
public:
  int getVelX() const;

  int getVelY() const;

private:
  int velY = 0;
};

#endif //GAMESERVER_DOT_H
