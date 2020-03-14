#include <sstream>
#include <iostream>

#include "GameState.hpp"
#include "GameOverState.hpp"
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

	this->_data->assets.LoadTexture("Bullet", BULLET_FILEPATH);

	this->_data->assets.LoadTexture("Asteroid 0", ASTEROID0_FILEPATH);
	this->_data->assets.LoadTexture("Asteroid 1", ASTEROID1_FILEPATH);
	this->_data->assets.LoadTexture("Asteroid 2", ASTEROID2_FILEPATH);
	this->_data->assets.LoadTexture("Asteroid 3", ASTEROID3_FILEPATH);


	ship = new SpaceShip(_data);
	asteroid = new Asteroid(_data);
	space = new Space(_data);
	cannon = new Cannon(_data);

	_background.setTexture(this->_data->assets.GetTexture("Game Background"));

	_gameState = GameStates::eReady;
}

void GameState::HandleInput()
{
	sf::Event event;

	while (this->_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			log_warn << "Close event recieved";
			this->_data->window.close();
		}

		if (sf::Event::KeyPressed)
		{
			if (GameStates::eGameOver != _gameState)
			{
				_gameState = GameStates::ePlaying;
				ship->PressKey();
			}
		}
	}
}

void GameState::Update(float dt)
{
	if (GameStates::eGameOver != _gameState)
	{
		space->MoveSpace(dt);
	}

	if (GameStates::ePlaying == _gameState)
	{
		asteroid->MoveAsteroids(dt);

		if (asteroid_clock.getElapsedTime().asSeconds() > ASTEROID_SPAWN_FREQUENCY)
		{
			asteroid->RandomiseAsteroidOffset();
			asteroid->SpawnAsteroid();
			asteroid_clock.restart();
		}

		if (cannon_clock.getElapsedTime().asSeconds() > CANNON_SHOOTING_FREQUENCY)
		{
			cannon->Shoot(ship->GetSprite().getPosition().x - 5, ship->GetSprite().getPosition().y - ship->GetSprite().getGlobalBounds().height / 2);
			cannon_clock.restart();
		}


		ship->Update(dt);
		cannon->Update(dt);

		std::vector<sf::Sprite> asteroidSprites = asteroid->GetSprites();
		std::vector<sf::Sprite> bulletSprites = cannon->GetSprites();

		for (int i = 0; i < asteroidSprites.size(); i++)
		{
			if (collision.CheckSpriteCollision(ship->GetSprite(), 0.625f, asteroidSprites.at(i), asteroidSprites.at(i).getScale().x))
			{
				_gameState = GameStates::eGameOver;
			}

			for (int j = 0; j < bulletSprites.size(); j++)
			{
				if (collision.CheckSpriteCollision(bulletSprites.at(j), 1, asteroidSprites.at(i), asteroidSprites.at(i).getScale().x))
				{
					asteroid->DeleteAsteroid(i);
					cannon->DeleteBullet(j);
					log << "Asteroid sprite deleted";
				}
			}
		}

		if (GameStates::ePlaying == _gameState)
		{
			//@TODO score system
		}
	}

	if (GameStates::eGameOver == _gameState)
	{
		this->_data->machine.AddState(StateRef(new GameOverState(_data, _score)), true);
	}
}

void GameState::Draw(float dt)
{
	this->_data->window.clear( sf::Color::Red );
	this->_data->window.draw(this->_background);

	space->DrawSpace();
	asteroid->DrawAsteroids();
	ship->Draw();
	cannon->Draw();

	this->_data->window.display();
}