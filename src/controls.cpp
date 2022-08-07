#include "controls.hpp"

Controls::Controls() {
  this->forward = false;
  this->reverse = false;
  this->left = false;
  this->right = false;
}

void Controls::HandleKeyboard() {
  this->forward = IsKeyDown(KEY_W);
  this->reverse = IsKeyDown(KEY_S);
  this->left = IsKeyDown(KEY_A);
  this->right = IsKeyDown(KEY_D);
}
