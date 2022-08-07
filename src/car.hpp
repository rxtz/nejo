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
#define MAX_SPEED 6.0
#define FRICTION 0.1
#define SENSITIVITY 0.03

class Car {
 private:
  Controls controls;

  void Move();

  void Update();

 public:
  Car(
    Texture2D texture,
    float x,
    float y,
    float scale
  );

  Texture2D texture;

  float x, y, scale, angle, speed, width, height;

  void Draw(bool debug = false);
};

#endif //NEJO_CAR_HPP
