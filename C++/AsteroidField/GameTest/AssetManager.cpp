#include "AssetManager.hpp"

void AssetManager::LoadTexture(std::string name, std::string fileName)
{
    log << "Trying to load texture from file: " << fileName;

    sf::Texture tex;

    if (tex.loadFromFile(fileName))
    {
        log << "Successfully loaded texture from file";
        this->_textures[name] = tex;
    }
    else
    {
        log_err << "Failed to load texture from file";
    }
}

sf::Texture& AssetManager::GetTexture(std::string name)
{
    if (_textures.find(name) != _textures.end())
    {
        return this->_textures.at(name);
    }

    log_err << "(@TODO return statement if false) Fail to get texture by name: " << name;
    return this->_textures.at(name);
}

void AssetManager::LoadFont(std::string name, std::string fileName)
{
    log << "Trying to load font from file: " << fileName;

    sf::Font font;

    if (font.loadFromFile(fileName))
    {
        log << "Successfully loaded";
        this->_fonts[name] = font;
    }
    else
    {
        log_err << "Failed to load font from file";
    }
}

sf::Font& AssetManager::GetFont(std::string name)
{
    log << "Trying to get font by name: " << name;
    return this->_fonts.at(name);
}