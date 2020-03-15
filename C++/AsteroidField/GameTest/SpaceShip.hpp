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

	void Update(float dt);

	void PressKey();

	const sf::Sprite& GetSprite() const;

private:
	GameDataRef _data;

	sf::Sprite _shipSprite;
	std::vector<sf::Texture> _animationFrames;

	sf::Clock _clock;

	sf::Clock _movementClock;

	int _shipState;
	float _spaceShipAcceleration;
	float _spaceShipMass;
};
