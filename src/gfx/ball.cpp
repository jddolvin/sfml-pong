#include "ball.h"

using namespace sf;

Ball::Ball(float startX, float startY) {
    position.x = startX;
    position.y = startY;

    ballShape.setRadius(5);
    ballShape.setPosition(position);
}

FloatRect Ball::getPosition() {
    return ballShape.getGlobalBounds();
}

CircleShape Ball::getShape() {
    return ballShape;
}

float Ball::getXVelocity() {
    return xVelocity;
}

void Ball::reboundSides() {
    xVelocity = -xVelocity;
}

void Ball::reboundBatOrTop() {
    position.y -= (yVelocity);
    yVelocity = -yVelocity;
}

void Ball::hitBottom(float startX, float startY) {
    position.x = startX;
    position.y = startY;
}

void Ball::update() {
    position.y += yVelocity;
    position.x += xVelocity;

    ballShape.setPosition(position);
}