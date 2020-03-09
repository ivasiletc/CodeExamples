#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

class Space
{
public:
	Space(GameDataRef data);

	void MoveSpace(float dt);
	void DrawSpace();

	const std::vector<sf::Sprite>& GetSprites() const;

private:
	GameDataRef _data;

	std::vector<sf::Sprite>_spaceSprites;
};

