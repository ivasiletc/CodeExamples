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
#include "HUD.hpp"

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
	HUD* hud;

	Collision collision;

	sf::Clock asteroid_clock;
	sf::Clock cannon_clock;

	int _gameState;

	sf::Clock score_clock;
	int _score;

	float _asteroidSpawnFrequency;
	float _cannonShootingFrequency;
};
