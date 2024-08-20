#include "TextureLoader.h"

void TextureLoader::load(objects::ID id, const std::string& filename) {
	std::unique_ptr<sf::Texture> texture(new sf::Texture());

	texture->loadFromFile(filename);

	textureMap.insert(std::make_pair(id, std::move(texture)));
};