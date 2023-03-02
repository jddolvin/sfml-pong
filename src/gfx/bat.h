#include <SFML/Graphics.hpp>

#ifndef SFML_PONG_BAT_H
#define SFML_PONG_BAT_H

class Bat {
private:
    sf::Vector2f position;

    sf::RectangleShape batShape;

    float batSpeed = 5.0f;

public:
    Bat(float startX, float startY);

    sf::FloatRect getPosition();

    sf::RectangleShape getShape();

    void moveLeft();

    void moveRight();

    void update();
};

#endif //SFML_PONG_BAT_H
