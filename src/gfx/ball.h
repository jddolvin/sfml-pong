#include <SFML/Graphics.hpp>

#ifndef SFML_PONG_BALL_H
#define SFML_PONG_BALL_H

class Ball {
private:
    sf::Vector2f position;

    sf::CircleShape ballShape;

    float xVelocity = 4.5f;
    float yVelocity = 4.5f;
public:
    Ball(float startX, float startY);

    sf::FloatRect getPosition();

    sf::CircleShape getShape();

    float getXVelocity();

    void reboundSides();

    void reboundBatOrTop();

    void hitBottom(float startX, float startY);

    void update();
};

#endif //SFML_PONG_BALL_H
