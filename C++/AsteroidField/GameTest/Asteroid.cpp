#include "Asteroid.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

Asteroid::Asteroid(GameDataRef data) : _data(data)
{
	_spaceWidth = SCREEN_WIDTH;
	_spaceHeight = SCREEN_HEIGHT;

	animationFrames.push_back(_data->assets.GetTexture("Explosion frame 0"));
	animationFrames.push_back(_data->assets.GetTexture("Explosion frame 1"));
	animationFrames.push_back(_data->assets.GetTexture("Explosion frame 2"));
	animationFrames.push_back(_data->assets.GetTexture("Explosion frame 3"));
	animationFrames.push_back(_data->assets.GetTexture("Explosion frame 4"));
	animationFrames.push_back(_data->assets.GetTexture("Explosion frame 5"));
	animationFrames.push_back(_data->assets.GetTexture("Explosion frame 6"));
	animationFrames.push_back(_data->assets.GetTexture("Explosion frame 7"));

	_randomDirection = -50.0f;
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

	_randomDirection += 0.01f;
	if (_randomDirection > 50.0f)
	{
		_randomDirection = -50.0f;
	}

	AsteroidSprite as;
	int tmp = rand() % 100;

	float rotationVelocity = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);;

	if (tmp < 40)
	{
		as = { sprite, -(_randomDirection * 0.01f), rotationVelocity, 0.0f};
	}
	else if(tmp < 80)
	{
		as = { sprite, (_randomDirection * 0.01f), -rotationVelocity, 0.0f};
	}
	else
	{
		as = { sprite, 0, -0.2f*rotationVelocity, 0.0f };
	}

	asteroidSprites.push_back(as);
}

void Asteroid::MoveAsteroids(float dt)
{
	for ( int i = 0; i < asteroidSprites.size(); i++)
	{
		if (asteroidSprites.at(i).asteroidSprite.getPosition().x < 0 - asteroidSprites.at(i).asteroidSprite.getLocalBounds().width			 ||
			asteroidSprites.at(i).asteroidSprite.getPosition().x > SCREEN_WIDTH + asteroidSprites.at(i).asteroidSprite.getLocalBounds().width  ||
			asteroidSprites.at(i).asteroidSprite.getPosition().y > SCREEN_HEIGHT + asteroidSprites.at(i).asteroidSprite.getLocalBounds().height)
		{
			DeleteAsteroid(i);
			log << "Asteroid was deleted (outside screen)";
		}
		else
		{
			sf::Vector2f position = asteroidSprites.at(i).asteroidSprite.getPosition();
			float movement = ASTEROID_MOVEMENT_SPEED * dt;

			asteroidSprites.at(i).asteroidSprite.move(asteroidSprites.at(i).direction, movement);
			asteroidSprites.at(i).asteroidSprite.setRotation(asteroidSprites.at(i).defaultRotationPosition += asteroidSprites.at(i).rotationVelocity);
		}
	}
}

void Asteroid::MoveExplosions(float dt)
{
	for (unsigned short int i = 0; i < explosionSprites.size(); i++)
	{
		float movement = (SPACESHIP_FORWARD_MOVEMENT_SPEED + ASTEROID_MOVEMENT_SPEED) * dt;

		if (explosionSprites.at(i).clock.getElapsedTime().asSeconds() > ASTEROID_EXPLOSION_DURATION / animationFrames.size())
		{
			explosionSprites.at(i).explosionSprite.setTexture(animationFrames.at(explosionSprites.at(i).animationIterator));
			explosionSprites.at(i).explosionSprite.setScale(explosionSprites.at(i).scale + 0.6f, explosionSprites.at(i).scale + 0.6f);
			explosionSprites.at(i).explosionSprite.setRotation(explosionSprites.at(i).rotation);
			explosionSprites.at(i).explosionSprite.move(0, movement);

			explosionSprites.at(i).clock.restart();
			explosionSprites.at(i).animationIterator++;

			if (explosionSprites.at(i).animationIterator == animationFrames.size())
			{
				explosionSprites.erase(explosionSprites.begin() + i);
			}
		}
	}
}

void Asteroid::DrawAsteroids()
{
	for (unsigned short int i = 0; i < asteroidSprites.size(); i++)
	{
		this->_data->window.draw(asteroidSprites.at(i).asteroidSprite);
	}
}

void Asteroid::DrawExplosions()
{
	for (unsigned short int i = 0; i < explosionSprites.size(); i++)
	{
		this->_data->window.draw(explosionSprites.at(i).explosionSprite);
	}
}

void Asteroid::RandomiseAsteroidOffset()
{
	_asteroidSpawnXOffset = rand() % (_spaceWidth + 1);
}

void Asteroid::DeleteAsteroid(int index)
{
	try
	{
		asteroidSprites.erase(asteroidSprites.begin() + index);
	}
	catch (const std::exception & e)
	{
		log_err << "Trying to delete no longer existing asteroid";
	}
}

void Asteroid::DestroyAsteroid(int index)
{
	try
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Explosion frame 0"));
		sprite.setPosition(asteroidSprites.at(index).asteroidSprite.getPosition().x, asteroidSprites.at(index).asteroidSprite.getPosition().y);
		ExplosionSprite es = { sprite, 0, asteroidSprites.at(index).asteroidSprite.getScale().x, asteroidSprites.at(index).asteroidSprite.getRotation() };
		explosionSprites.push_back(es);

		DeleteAsteroid(index);
		log << "Asteroid with index " << index << "was destroyed";
	}
	catch (const std::exception & e)
	{
		log_err << "Trying to get asteroid position from no longer existing asteroid";
	}
}

const std::vector<AsteroidSprite> &Asteroid::GetSprites() const
{
	return asteroidSprites;
}