#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "logger.h"
#include "Game.hpp"
#include "Space.hpp"
#include "Collision.hpp"
#include "SpaceShip.hpp"
#include "Asteroid.hpp"
#include "Cannon.hpp"

class GameState : public State
{
public:
	GameState(GameDataRef data);

	void Init();

	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataRef _data;

	sf::Sprite _background;

	Space* space;
	Asteroid* asteroid;
	SpaceShip* ship;
	Cannon* cannon;

	Collision collision;

	sf::Clock asteroid_clock;
	sf::Clock cannon_clock;

	int _gameState;

	sf::RectangleShape _gameOverFlash;

	sf::Clock score_clock;
	int _score;

	float _asteroidSpawnFrequency;
	float _cannonShootingFrequency;
};
