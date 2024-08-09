#pragma once
#include <SFML/Graphics.hpp>

class Kumar
{
public:
    Kumar();
    void run();
private:
    void processEvent(sf::Time);
    void update(sf::Keyboard::Key, bool, sf::Time);
    void renderer();
    void movement(int, float, sf::Time);
private:
    sf::RenderWindow render;
    sf::CircleShape circle;
};