#include <sstream>
#include <iostream>

#include "GameState.hpp"
#include "GameOverState.hpp"
#include "DEFINITIONS.hpp"

GameState::GameState(GameDataRef data) : _data(data)
{
	log << "constructor was called";
	_asteroidSpawnFrequency = ASTEROID_SPAWN_FREQUENCY;
	_cannonShootingFrequency = CANNON_SHOOTING_FREQUENCY;
}

void GameState::Init()
{
	log << "function was called";

	this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
	this->_data->assets.LoadTexture("Space", SPACE_FILEPATH);

	this->_data->assets.LoadFont("Castelar Font", FONT_FILEPATH);

	this->_data->assets.LoadTexture("Ship turning left", SHIP_LEFT_FILEPATH);
	this->_data->assets.LoadTexture("Ship turning right", SHIP_RIGHT_FILEPATH);
	this->_data->assets.LoadTexture("Ship main", SHIP_MAIN_FILEPATH);
	this->_data->assets.LoadTexture("Ship main flame", SHIP_MAIN_FLAME_FILEPATH);

	this->_data->assets.LoadTexture("Bullet", BULLET_FILEPATH);

	this->_data->assets.LoadTexture("Asteroid 0", ASTEROID0_FILEPATH);
	this->_data->assets.LoadTexture("Asteroid 1", ASTEROID1_FILEPATH);
	this->_data->assets.LoadTexture("Asteroid 2", ASTEROID2_FILEPATH);
	this->_data->assets.LoadTexture("Asteroid 3", ASTEROID3_FILEPATH);

	this->_data->assets.LoadTexture("Explosion frame 0", ASTEROID_EXPLOSION0_FILEPATH);
	this->_data->assets.LoadTexture("Explosion frame 1", ASTEROID_EXPLOSION1_FILEPATH);
	this->_data->assets.LoadTexture("Explosion frame 2", ASTEROID_EXPLOSION2_FILEPATH);
	this->_data->assets.LoadTexture("Explosion frame 3", ASTEROID_EXPLOSION3_FILEPATH);
	this->_data->assets.LoadTexture("Explosion frame 4", ASTEROID_EXPLOSION4_FILEPATH);
	this->_data->assets.LoadTexture("Explosion frame 5", ASTEROID_EXPLOSION5_FILEPATH);
	this->_data->assets.LoadTexture("Explosion frame 6", ASTEROID_EXPLOSION6_FILEPATH);
	this->_data->assets.LoadTexture("Explosion frame 7", ASTEROID_EXPLOSION7_FILEPATH);


	ship = new SpaceShip(_data);
	asteroid = new Asteroid(_data);
	space = new Space(_data);
	cannon = new Cannon(_data);
	hud = new HUD(_data);

	_background.setTexture(this->_data->assets.GetTexture("Game Background"));
	_score = 0;

	hud->UpdateScore(_score);

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
		asteroid->MoveExplosions(dt);

		if (asteroid_clock.getElapsedTime().asSeconds() > 1)
		{
			_asteroidSpawnFrequency += ASTEROID_SPAWN_FREQUENCY_INCREASING;
		}

		if (_asteroidSpawnFrequency > 0)
		{
			if (asteroid_clock.getElapsedTime().asSeconds() > 1 / _asteroidSpawnFrequency)
			{
				asteroid->RandomiseAsteroidOffset();
				asteroid->SpawnAsteroid();
				asteroid_clock.restart();
			}
		}

		if (_cannonShootingFrequency > 0)
		{
			if (cannon_clock.getElapsedTime().asSeconds() > 1 / _cannonShootingFrequency)
			{
				cannon->Shoot(ship->GetSprite().getPosition().x - 5, ship->GetSprite().getPosition().y - ship->GetSprite().getGlobalBounds().height / 2);
				cannon_clock.restart();
			}
		}

		ship->Update(dt);
		cannon->Update(dt);

		std::vector<AsteroidSprite> asteroidSprites = asteroid->GetSprites();
		std::vector<sf::Sprite> bulletSprites = cannon->GetSprites();

		for (int i = 0; i < asteroidSprites.size(); i++)
		{
			if (collision.CheckSpriteCollision(ship->GetSprite(), 0.625f, asteroidSprites.at(i).asteroidSprite, asteroidSprites.at(i).asteroidSprite.getScale().x))
			{
				_gameState = GameStates::eGameOver;
			}
		}


		for (int i = 0; i < asteroidSprites.size(); i++)
		{
			for (int j = 0; j < bulletSprites.size(); j++)
			{
				if (collision.CheckSpriteCollision(bulletSprites.at(j), 1, asteroidSprites.at(i).asteroidSprite, asteroidSprites.at(i).asteroidSprite.getScale().x))
				{
					asteroid->DestroyAsteroid(i);
					cannon->DeleteBullet(j);
					break;
				}
			}
		}


		if (GameStates::ePlaying == _gameState)
		{
			if (score_clock.getElapsedTime().asSeconds() > SCORE_INCREASING_TIME)
			{
				_score++;
				hud->UpdateScore(_score);
				score_clock.restart();
			}
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
	asteroid->DrawExplosions();
	ship->Draw();
	cannon->Draw();

	hud->Draw();

	this->_data->window.display();
}