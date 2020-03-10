#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Land.hpp"
#include "Collision.hpp"

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

	Land* land;
	Collision collision;

	sf::Clock clock;

	int _gameState;

	sf::RectangleShape _gameOverFlash;
	bool _flashOn;

	int _score;

};
