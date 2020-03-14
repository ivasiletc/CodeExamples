#include "Asteroid.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

Asteroid::Asteroid(GameDataRef data) : _data(data)
{
	_spaceWidth = SCREEN_WIDTH;
	_spaceHeight = SCREEN_HEIGHT;

	_asteroidSpawnXOffset = 0;
}

void Asteroid::SpawnAsteroid()
{
	int AsteroidRandomTexture = rand() % (ASTEROID_TEXTURES_AMOUNT);

	float AsteroidRandomSize = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

	if (AsteroidRandomSize < 0.2f)
	{
		AsteroidRandomSize += 0.2f;
	}

	sf::Sprite sprite(this->_data->assets.GetTexture("Asteroid " + std::to_string(AsteroidRandomTexture)));

	sprite.setScale(AsteroidRandomSize, AsteroidRandomSize);
	sprite.setPosition(_asteroidSpawnXOffset, 0 - sprite.getGlobalBounds().height);
	log << "Asteroid was spawned at X: " << _asteroidSpawnXOffset << " Y: " << 0 - sprite.getGlobalBounds().height;
	asteroidSprites.push_back(sprite);
}

void Asteroid::MoveAsteroids(float dt)
{
	for ( int i = 0; i < asteroidSprites.size(); i++)
	{
		if (asteroidSprites.at(i).getPosition().x < 0 - asteroidSprites.at(i).getLocalBounds().width			 ||
			asteroidSprites.at(i).getPosition().x > SCREEN_WIDTH + asteroidSprites.at(i).getLocalBounds().width  ||
			asteroidSprites.at(i).getPosition().y > SCREEN_HEIGHT + asteroidSprites.at(i).getLocalBounds().height)
		{
			asteroidSprites.erase( asteroidSprites.begin( ) + i );
			log << "Asteroid was deleted";
		}
		else
		{
			sf::Vector2f position = asteroidSprites.at(i).getPosition();
			float movement = ASTEROID_MOVEMENT_SPEED * dt;

			asteroidSprites.at(i).move(0, movement);
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
	_asteroidSpawnXOffset = rand() % (_spaceWidth + 1);
}

void Asteroid::DeleteAsteroid(int index)
{
	asteroidSprites.erase(asteroidSprites.begin() + index);
}

const std::vector<sf::Sprite> &Asteroid::GetSprites() const
{
	return asteroidSprites;
}