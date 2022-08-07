#include "assets.hpp"

void Print(
  int x, int y, const char *text,
  unsigned short font_size, Color color
) {
  static const Font la_fuente = LoadFont(ASSETS FONT_FAMILY);
  const Vector2 position{float(x), float(y)};
  DrawTextEx(la_fuente, text, position, font_size, 1, color);
}

void ShowInfo() {
  const Vector2 mouse_position = GetMousePosition();
  Print(MG, MG, TextFormat(
    "%u FPS  (%.f, %.f)", GetFPS(), mouse_position.x, mouse_position.y
  ));
}
