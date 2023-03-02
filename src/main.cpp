#include <sstream>
#include <cstdlib>
#include <ctime>

#include <SFML/Graphics.hpp>
#include "./gfx/bat.h"
#include "./gfx/ball.h"

using namespace sf;

int main() {
    int windowWidth = 800;
    int windowHeight = 600;

    RenderWindow window(VideoMode(windowWidth, windowHeight), "Pong");
    window.setFramerateLimit(60);

    int score = 0;
    int lives = 3;

    Text hud;
    std::stringstream ss;

    Font font;

    font.loadFromFile("../src/game-over.ttf");

    hud.setFont(font);
    hud.setCharacterSize(75);
    hud.setFillColor(Color::White);

    ss << "Score: " << score << " Lives: " << lives;
    hud.setString(ss.str());

    hud.setPosition((windowWidth / 2) - (hud.getGlobalBounds().width / 2), -40);

    Bat bat(windowWidth / 2, windowHeight - 20);
    Ball ball(windowWidth / 2, hud.getGlobalBounds().height * 2);


    while (window.isOpen()) {
        Event event{};
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Left) && bat.getPosition().left > 0) {
            bat.moveLeft();
        } else if (Keyboard::isKeyPressed(Keyboard::Right) &&
                   bat.getPosition().left + bat.getPosition().width < windowWidth) {
            bat.moveRight();
        } else if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        if (ball.getPosition().top > windowHeight) {
            srandom(time(nullptr));
            long randomEntry = random() % windowWidth;
            ball.hitBottom(randomEntry, hud.getGlobalBounds().height * 2);
            lives--;
            if (lives < 1) {
                score = 0;
                lives = 3;
            }
        }
        if (ball.getPosition().top < hud.getGlobalBounds().height * 2) {
            ball.reboundBatOrTop();
            score++;
        }
        if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth) {
            ball.reboundSides();
        }
        if (ball.getPosition().intersects(bat.getPosition()) || ball.getPosition().intersects(bat.getPosition())) {
            ball.reboundBatOrTop();
        }

        ball.update();
        bat.update();

        ss.str("");
        ss << "Score: " << score << " Lives: " << lives;
        hud.setString(ss.str());

        window.clear(Color::Black);
        window.draw(bat.getShape());
        window.draw(ball.getShape());
        window.draw(hud);
        window.display();
    }

    return 0;
}