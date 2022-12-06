#ifndef NEJO_ROAD_HPP
#define NEJO_ROAD_HPP

#include <raylib.h>
#include <cmath>

#include "assets.hpp"

//#define INFINITY 1'000'000
#define STROKE 10
#define DASH 64
#define LINE_COLOR LIGHTGRAY
#define DASH_COLOR YELLOW

class Road {
 public:
  Road(float x, float width, unsigned short lanes = 4);

  float x, width;
  unsigned short lanes;

  float /*top, bottom, */left, right;

//  Vector2 top_left{}, top_right{}, bottom_left{}, bottom_right{};

//  static Vector2 borders[2][2];

  float GetLaneCenter(unsigned short index);

  void Draw(bool debug = false);
};

#endif //NEJO_ROAD_HPP
