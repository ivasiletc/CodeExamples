#include "Asteroid.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

Asteroid::Asteroid(GameDataRef data) : _data(data)
{
	_spaceWidth = this->_data->assets.GetTexture("Space").getSize().x;
	_asteroidSpawnYOffset = 0;
}

void Asteroid::SpawnAsteroid()
{
	sf::Sprite sprite(this->_data->assets.GetTexture("Scoring Asteroid"));

	sprite.setPosition(this->_data->window.getSize().x, 0);

	asteroidSprites.push_back(sprite);
}

void Asteroid::MoveAsteroids(float dt)
{
	for ( int i = 0; i < asteroidSprites.size(); i++)
	{
		if (asteroidSprites.at(i).getPosition().x < 0 - asteroidSprites.at(i).getLocalBounds().width)
		{
			asteroidSprites.erase( asteroidSprites.begin( ) + i );
		}
		else
		{
			sf::Vector2f position = asteroidSprites.at(i).getPosition();
			float movement = ASTEROID_MOVEMENT_SPEED * dt;

			asteroidSprites.at(i).move(-movement, 0);
		}
	}
}

void Asteroid::DrawAsteroids()
{
	for (unsigned short int i = 0; i < asteroidSprites.size(); i++)
	{
		this->_data->window.draw(asteroidSprites.at(i));
	}
}

void Asteroid::RandomiseAsteroidOffset()
{
	_asteroidSpawnYOffset = rand() % (_spaceWidth + 1);
}

const std::vector<sf::Sprite> &Asteroid::GetSprites() const
{
	return asteroidSprites;
}