#ifndef NEJO_CONTROLS_HPP
#define NEJO_CONTROLS_HPP

#include <raylib.h>

class Controls {
 public:
  Controls();

  bool forward, reverse, left, right;

  void HandleKeyboard();
};

#endif //NEJO_CONTROLS_HPP
