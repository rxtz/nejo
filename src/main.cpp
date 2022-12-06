#include "main.hpp"

int main() {
  InitWindow(WIN_W, WIN_H, "nejo");

  SetTargetFPS(60);

  static const Texture2D ferra_texture = LoadTexture(ASSETS "ferrari.png");

  Road calle{float(WIN_W) / 2, float(WIN_W) * 4 / 5};

  Car ferra{ferra_texture, calle.GetLaneCenter(2), float(WIN_H) / 2, 1.25};

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(Color{63, 63, 63});

    calle.Draw(DEBUG);
    ferra.Draw(DEBUG);

    ShowInfo();
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
