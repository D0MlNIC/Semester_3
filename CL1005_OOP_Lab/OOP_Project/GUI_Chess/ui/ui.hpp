#ifndef UI_H
#define UI_H

#include "../game/game.hpp"

namespace chess {
class BaseUI {
public:
  Game game;
  virtual void render(const int port = 8080) = 0;
};

} 

#endif
