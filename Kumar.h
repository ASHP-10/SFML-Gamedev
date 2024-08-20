#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

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
    sf::Texture texS;
    // sf::Time deltaTime;
    sf::Time timeElapsed;
    sf::Time timePerFrame;
};

namespace objects {
    enum ID { adarsh, kumar, midhun};
};