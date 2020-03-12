#pragma once

#include <map>

#include <SFML/Graphics.hpp>

#include "logger.h"

class AssetManager
{
public:
    AssetManager() { log << "constructor was called"; };
    ~AssetManager() { log << "WARN: destructor was called"; };

    void LoadTexture(std::string name, std::string fileName);
    sf::Texture& GetTexture(std::string name);

    void LoadFont(std::string name, std::string fileName);
    sf::Font& GetFont(std::string name);

private:
    std::map<std::string, sf::Texture> _textures;
    std::map<std::string, sf::Font> _fonts;
};

