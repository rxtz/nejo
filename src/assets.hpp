#ifndef NEJO_ASSETS_HPP
#define NEJO_ASSETS_HPP

#include <raylib.h>

#define WIN_W 640
#define WIN_H 640

#define ASSETS "../assets/"
#define FONT_FAMILY "JetBrainsMonoNL-Regular.ttf"
#define FONT_SIZE 16
#define MG 8 // margin

void Print(int x, int y, const char *text, Color color = LIGHTGRAY);

void ShowInfo();

float Lerp(float a, float b, float t);

#endif //NEJO_ASSETS_HPP
