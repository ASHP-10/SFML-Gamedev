#include "Kumar.h"

Kumar::Kumar() :
    render(sf::VideoMode(1000, 1000), "Johnny"), circle()
{
    circle.setFillColor(sf::Color::Magenta);
    circle.setRadius(30.32f);
}

void Kumar::run() {

    sf::Clock clock;

    sf::Time deltaTime = clock.restart();
    while (render.isOpen()) {
        processEvent(deltaTime);
        renderer();  
    }
}

void Kumar::renderer() { 
    render.clear();
    render.draw(circle);
    render.display();
}

void Kumar::processEvent(sf::Time deltaTime) {
    sf::Event event;

    while (render.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed: {
                Kumar::update(event.key.code, true, deltaTime);
                break;
            }
        }
    }
}

void Kumar::update(sf::Keyboard::Key key, bool isKeyPressed, sf::Time deltaTime) {
    if (!isKeyPressed)
        return;

    switch (key) { 
        case sf::Keyboard::Key::D: {
            Kumar::movement(0,5.0f, deltaTime); // 0 for x-axis and 1 for y-axis
            break;
        }
        case sf::Keyboard::Key::W: {
            Kumar::movement(1,-5.0f, deltaTime);
            break;
        }
        case sf::Keyboard::Key::A: {
            Kumar::movement(0,-5.0f, deltaTime);
            break;
        }
        case sf::Keyboard::Key::S: {
            Kumar::movement(1,5.0f, deltaTime);
            break;
        }
    }
}

void Kumar::movement(int axis, float p, sf::Time deltaTime) {
    sf::Vector2f pos(0.f, 0.f);

    if (axis == 0)
        pos.x += p;
    else
        pos.y += p;

    circle.move(pos * deltaTime.asSeconds());
}