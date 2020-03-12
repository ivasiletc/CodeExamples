#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "logger.h"
#include "Game.hpp"
#include "Space.hpp"
#include "Collision.hpp"
#include "SpaceShip.hpp"
#include "Asteroid.hpp"

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

	Collision collision;

	sf::Clock clock;

	int _gameState;

	sf::RectangleShape _gameOverFlash;

	int _score;

};
