#ifndef GUI_HPP
#define GUI_HPP

#include "../ui.hpp"
#include "../../utils/utils.hpp"
#include <cassert>

#include <iostream>
#include <string>

using std::cout, std::string;

namespace chess {
  class GUI : public BaseUI {
    public:
      void render(const int port = 0) override;
    };
}

#endif