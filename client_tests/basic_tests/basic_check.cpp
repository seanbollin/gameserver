#include "gtest/gtest.h"
#include "Dot.h"

TEST(basic_check, test_eq) {
  Dot dot;

  SDL_Event event;

  SDL_Keysym keysym = {};
  keysym.sym = SDLK_UP;

  SDL_KeyboardEvent keyboardEvent = {};
  keyboardEvent.type = SDL_KEYDOWN;
  keyboardEvent.keysym = keysym;
  event.key = keyboardEvent;

  dot.handleEvent(event);

  EXPECT_EQ(-Dot::DOT_VEL, dot.getVelY());
}

