#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"

class Cannon
{
public:
	Cannon(GameDataRef data);
	~Cannon() {};

	void Draw();

	void Update(float dt);

	const std::vector<sf::Sprite>& GetSprites() const;

	void Shoot(int x, int y);
	void DeleteBullet(int index);

private:
	GameDataRef _data;

	std::vector<sf::Sprite> bulletSprites;
	sf::Texture bulletTexture;

	sf::Clock _clock;

};
