#ifndef NEJO_CAR_HPP
#define NEJO_CAR_HPP

#include <raylib.h>
#include <cmath>

#include "controls.hpp"
#include "assets.hpp"

// initial physics
#define ANGLE 0.0
#define SPEED 0.0
#define ACCELERATION 0.2
#define MAX_SPEED INFINITY
#define FRICTION 0.1
#define SENSITIVITY 0.03

class Car {
 private:
  Controls controls;

  void Move();

  void Update();

 public:
  Car(Texture2D texture, float x, float y, float scale = 1);

  Texture2D texture;

  float x, y, scale, width, height, angle, speed;

  void Draw(bool debug = false);
};

#endif //NEJO_CAR_HPP
