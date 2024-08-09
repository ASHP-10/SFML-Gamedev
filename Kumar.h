#pragma once
#include <SFML/Graphics.hpp>

class Kumar
{
public:
    Kumar();
    void run();
private:
    void processEvent();
    void update(sf::Keyboard::Key, bool);
    void renderer();
    void movement(int, float);
private:
    sf::RenderWindow render;
    sf::CircleShape circle;
    sf::Time deltaTime;
};