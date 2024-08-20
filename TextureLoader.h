#pragma once

#include "Kumar.h"
#include <iostream>
#include <map>
class TextureLoader
{
public:
	void load(objects::ID, const std::string&);

private:
	std::map<objects::ID, std::unique_ptr<sf::Texture>> textureMap;
};

