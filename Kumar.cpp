#include "Kumar.h"

Kumar::Kumar() :
    render(sf::VideoMode(1000, 1000), "kabuto san"), circle()
{
    circle.setFillColor(sf::Color::Blue);
    circle.setRadius(30.32f);
    circle.setPosition(500, 500);
}

void Kumar::run() {

    sf::Clock clock;                        // starts the stopwatch time

    while (render.isOpen()) {
        deltaTime = clock.restart();       // returns the elapsed time and restarts the stopwatch
        processEvent();
        renderer();  
    }
}

void Kumar::renderer() { 
    render.clear();
    render.draw(circle);
    render.display();
}

void Kumar::processEvent() {
    sf::Event event;

    while (render.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed: {
                    render.close();
            }
            case sf::Event::KeyPressed: {
                    Kumar::update(event.key.code, true);
                    break;
            }
        }
    }
}

void Kumar::update(sf::Keyboard::Key key, bool isKeyPressed) {
    if (!isKeyPressed)
        return;

    float playerSpeed = 2000.0f;

    switch (key) { 
        case sf::Keyboard::Key::W: {
            Kumar::movement(1,-playerSpeed);
            break;
        }
        case sf::Keyboard::Key::A: {
            Kumar::movement(0,-playerSpeed);
            break;
        }
        case sf::Keyboard::Key::S: {
            Kumar::movement(1,playerSpeed);
            break;
        }
        case sf::Keyboard::Key::D: {
            Kumar::movement(0, playerSpeed); // 0 for x-axis and 1 for y-axis
            break;
        }
    }
}

void Kumar::movement(int axis, float playerSpeed) {
    sf::Vector2f pos(0.f, 0.f);

    if (axis == 0)
        pos.x += playerSpeed;
    else
        pos.y += playerSpeed;

    circle.move(pos * deltaTime.asSeconds());
}