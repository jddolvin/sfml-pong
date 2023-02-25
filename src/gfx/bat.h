#include <SFML/Graphics.hpp>

#ifndef SFML_PONG_BAT_H
#define SFML_PONG_BAT_H

using namespace sf;

class Bat {
private:
    Vector2f position;

    RectangleShape batShape;

    float batSpeed = .3f;

public:
    Bat(float startX, float startY);

    FloatRect getPosition();

    RectangleShape getShape();

    void moveLeft();

    void moveRight();

    void update();
};

#endif //SFML_PONG_BAT_H
