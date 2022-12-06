#include "car.hpp"

Car::Car(Texture2D texture, float x, float y, float scale)
  : texture(texture), x(x), y(y), scale(scale) {
  width = scale * float(texture.width);
  height = scale * float(texture.height);

  angle = ANGLE;
  speed = SPEED;
}

void Car::Move() {
  if (IsKeyDown(KEY_SPACE)) {
    angle = /*speed = */0;
    x = (IsCursorOnScreen() ? GetMousePosition().x : float(WIN_W) / 2);
    y = (IsCursorOnScreen() ? GetMousePosition().y : float(WIN_H) / 2);
    return;
  }

  static const float hei = height / 2;

  if (y - hei > WIN_H) {
    y = -hei;
  }
  if (y + hei < 0) {
    y = WIN_H + hei;
  }

  static const float max_speed = MAX_SPEED * scale;

  if (controls.forward) {
    speed += ACCELERATION;
  }

  if (controls.reverse) {
    speed -= ACCELERATION;
  }

  if (speed > max_speed) {
    speed = max_speed; // multa
  }

  if (speed < -max_speed / 2) {
    speed = -max_speed / 2;
  }

  if (speed > 0) {
    speed -= FRICTION;
  }
  if (speed < 0) {
    speed += FRICTION;
  }
  if (std::abs(speed) < FRICTION) {
    speed = 0;
  }

  if (speed != 0) {
    const float TURN = SENSITIVITY * (speed > 0 ? 1 : -1);

    if (controls.left) {
      angle += TURN;
    }
    if (controls.right) {
      angle -= TURN;
    }
  }

  x -= std::sin(angle) * speed;
  y -= std::cos(angle) * speed;
}

void Car::Update() {
  controls.HandleKeyboard();
  Move();
}

void Car::Draw(bool debug) {
  Update();

  if (debug) {
    Print(MG, MG * 3, TextFormat(
      "(%.2f, %.2f)  %.2f  %.2f", x, y, speed, angle * RAD2DEG
    ), BLUE);
  }

  Vector2 position{x - width / 2, y - height / 2};

  const unsigned char z = std::max<int>(0, int(255 - 2 * std::abs(speed)));

  DrawTextureEx(texture, position, -angle * RAD2DEG, scale, Color{255, z, z, 255});
}
