#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"

#include <vector>

class SpaceShip
{
public:
	SpaceShip(GameDataRef data);
	~SpaceShip();

	void Draw();

	void Animate(float dt);

	void Update(float dt);

	const sf::Sprite& GetSprite() const;

private:
	GameDataRef _data;

	sf::Sprite _shipSprite;
	std::vector<sf::Texture> _animationFrames;

	unsigned int _animationIterator;

	sf::Clock _clock;

	sf::Clock _movementClock;

	int _shipState;

};
