#include "main.hpp"

int main() {
  InitWindow(WIN_W, WIN_H, "nejo");

  SetTargetFPS(60);

  static const Texture2D ferra_texture = LoadTexture(ASSETS "ferrari.png");

  Car ferra{ferra_texture, float(WIN_W) / 2, float(WIN_H) / 2, 1};

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(DARKGRAY);
    ShowInfo();

    ferra.Draw(true);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
