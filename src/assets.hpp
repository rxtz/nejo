#ifndef NEJO_ASSETS_HPP
#define NEJO_ASSETS_HPP

#include <raylib.h>

#define ASSETS "../assets/"
#define FONT_FAMILY "JetBrainsMonoNL-Regular.ttf"
#define FONT_SIZE 16
#define MG 8 // margin

void Print(
  int x, int y, const char *text,
  unsigned short font_size = FONT_SIZE, Color color = LIGHTGRAY
);

void ShowInfo();

#endif //NEJO_ASSETS_HPP
