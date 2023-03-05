#include "ball.h"

using namespace sf;

Ball::Ball(float startX, float startY) {
    position.x = startX;
    position.y = startY;

    ballShape.setRadius(5);
    ballShape.setPosition(position);

    ballSound.setBuffer(ballHitBuffer);
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
    ballHitBuffer.loadFromFile("../src/assets/sound/wall-bump.wav");
    ballSound.setPitch(1.0f);
    ballSound.play();
}

void Ball::reboundBatOrTop(bool isBat) {
    position.y -= (yVelocity);
    yVelocity = -yVelocity;
    if (isBat) {
        ballHitBuffer.loadFromFile("../src/assets/sound/bat-bump.wav");
    } else {
        ballHitBuffer.loadFromFile("../src/assets/sound/wall-bump.wav");
    }
    ballSound.setPitch(1.0f);
    ballSound.play();
}

void Ball::hitBottom(float startX, float startY) {
    position.x = startX;
    position.y = startY;
    ballHitBuffer.loadFromFile("../src/assets/sound/bat-bump.wav");
    ballSound.setPitch(0.2f);
    ballSound.play();
}

void Ball::update() {
    position.y += yVelocity;
    position.x += xVelocity;

    ballShape.setPosition(position);
}