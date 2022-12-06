#include "controls.hpp"

Controls::Controls() {
  forward = false;
  reverse = false;
  left = false;
  right = false;
}

void Controls::HandleKeyboard() {
  forward = IsKeyDown(KEY_W);
  reverse = IsKeyDown(KEY_S);
  left = IsKeyDown(KEY_A);
  right = IsKeyDown(KEY_D);
}
