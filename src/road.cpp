#include "road.hpp"

Road::Road(float x, float width, unsigned short lanes)
  : x(x), width(width), lanes(lanes) {
//  top = -INFINITY;
//  bottom = INFINITY;
  left = x - width / 2;
  right = x + width / 2;

//  top_left = {left, top};
//  top_right = {right, top};
//  bottom_left = {left, bottom};
//  bottom_right = {right, bottom};

//  static Vector2 borders[2][2] = {
//    {top_left,  bottom_left},
//    {top_right, bottom_right}
//  };
}

float Road::GetLaneCenter(unsigned short index) {
  static const float lane_width = width / float(lanes);
  return left + lane_width / 2 + float(std::min<int>(index, lanes - 1)) * lane_width;
}

void Road::Draw(bool debug) {
  if (debug) {

  }

  static const Rectangle road{left, -STROKE, width, WIN_H + 2 * STROKE};
  DrawRectangleLinesEx(road, STROKE, LINE_COLOR);

  for (unsigned short i = 1; i <= lanes - 1; ++i) {
    const float lane_x = Lerp(left, right, float(i) / float(lanes));

    for (unsigned short j = 0; j < WIN_H; j += DASH) {
      if ((j / DASH) % 2 == 0) {
        Vector2
          start{lane_x - STROKE / float(lanes), float(j)},
          end{lane_x - STROKE / float(lanes), float(j + DASH)};

        DrawLineEx(start, end, STROKE, DASH_COLOR);
      }
    }
  }
}
