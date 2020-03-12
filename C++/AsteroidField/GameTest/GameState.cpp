#include <sstream>
#include <iostream>

#include "GameState.hpp"
#include "DEFINITIONS.hpp"

GameState::GameState(GameDataRef data) : _data(data)
{
	log << "constructor was called";
}

void GameState::Init()
{
	log << "function was called";

	this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
	this->_data->assets.LoadTexture("Space", SPACE_FILEPATH);

	this->_data->assets.LoadTexture("Ship turning left", SHIP_LEFT_FILEPATH);
	this->_data->assets.LoadTexture("Ship turning right", SHIP_RIGHT_FILEPATH);
	this->_data->assets.LoadTexture("Ship main", SHIP_MAIN_FILEPATH);

	ship = new SpaceShip(_data);
	asteroid = new Asteroid(_data);

	_background.setTexture(this->_data->assets.GetTexture("Game Background"));

	_gameState = GameStates::eReady;
}

void GameState::HandleInput()
{
	log << "function was called";

	sf::Event event;

	while (this->_data->window.pollEvent(event))
	{
		log << "Event: " << event.type;

		if (sf::Event::Closed == event.type)
		{
			log_warn << "Close event recieved";
			this->_data->window.close();
		}

		if (this->_data->input.IsSpriteClicked(this->_background, sf::Mouse::Left, this->_data->window))
		{
			if (GameStates::eGameOver != _gameState)
			{
				log << "Left mouse clicked";
				_gameState = GameStates::ePlaying;
			}
		}
	}
	log << "end function";
}

void GameState::Update(float dt)
{
	if (GameStates::eGameOver != _gameState)
	{
		ship->Animate(dt);
		space->MoveSpace(dt);
	}

	if (GameStates::ePlaying == _gameState)
	{
		asteroid->MoveAsteroids(dt);

		if (clock.getElapsedTime().asSeconds() > ASTEROID_SPAWN_FREQUENCY)
		{
			asteroid->RandomiseAsteroidOffset();

			asteroid->SpawnAsteroid();

			clock.restart();
		}

		ship->Update(dt);

		std::vector<sf::Sprite> spaceSprites = space->GetSprites();

		for (int i = 0; i < spaceSprites.size(); i++)
		{
			if (collision.CheckSpriteCollision(ship->GetSprite(), 0.7f, spaceSprites.at(i), 1.0f))
			{
				_gameState = GameStates::eGameOver;
			}
		}

		std::vector<sf::Sprite> asteroidSprites = asteroid->GetSprites();

		for (int i = 0; i < asteroidSprites.size(); i++)
		{
			if (collision.CheckSpriteCollision(ship->GetSprite(), 0.625f, asteroidSprites.at(i), 1.0f))
			{
				_gameState = GameStates::eGameOver;
			}
		}

		if (GameStates::ePlaying == _gameState)
		{
			log << "@TODO score system";
		}
	}

	if (GameStates::eGameOver == _gameState)
	{
		log << "Game over";
	}
}

void GameState::Draw(float dt)
{
	log << "function was called";

	this->_data->window.clear( sf::Color::Red );
	this->_data->window.draw(this->_background);

	asteroid->DrawAsteroids();
	space->DrawSpace();
	ship->Draw();

	this->_data->window.display();
}