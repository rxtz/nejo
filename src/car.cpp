#include "car.hpp"

Car::Car(
  Texture2D texture,
  float x,
  float y,
  float scale
) : texture(texture), x(x), y(y), scale(scale) {
  this->width = scale * float(texture.width);
  this->height = scale * float(texture.height);

  this->angle = ANGLE;
  this->speed = SPEED;
}

void Car::Move() {
  if (this->controls.forward) {
    this->speed += ACCELERATION;
  }

  if (this->controls.reverse) {
    this->speed -= ACCELERATION;
  }

  if (this->speed > MAX_SPEED) {
    this->speed = MAX_SPEED; // multa
  }

  if (this->speed < -MAX_SPEED / 2) {
    this->speed = -MAX_SPEED / 2;
  }

  if (this->speed > 0) {
    this->speed -= FRICTION;
  }
  if (this->speed < 0) {
    this->speed += FRICTION;
  }
  if (std::abs(this->speed) < FRICTION) {
    this->speed = 0;
  }

  if (this->speed != 0) {
    const float TURN = SENSITIVITY * (this->speed > 0 ? 1 : -1);

    if (this->controls.left) {
      this->angle += TURN;
    }
    if (this->controls.right) {
      this->angle -= TURN;
    }
  }

  this->x -= std::sin(this->angle) * this->speed;
  this->y -= std::cos(this->angle) * this->speed;
}

void Car::Update() {
  this->controls.HandleKeyboard();
  this->Move();
}

void Car::Draw(bool debug) {
  this->Update();

  if (debug) {
    Print(MG, MG * 3, TextFormat(
      "(%.2f, %.2f)  %.2f", this->x, this->y,
      this->angle * RAD2DEG
    ));
  }

  Vector2 position{
    this->x - this->width / 2,
    this->y - this->height / 2
  };

  DrawTextureEx(
    this->texture,
    position,
    -angle * RAD2DEG,
    this->scale,
    WHITE
  );
}
