#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

struct AsteroidSprite
{
	sf::Sprite asteroidSprite;
	float direction;
	float rotationVelocity;
	float defaultRotationPosition;
};

struct ExplosionSprite
{
	sf::Sprite explosionSprite;
	unsigned int animationIterator;
	float scale;
	float rotation;
	sf::Clock clock;
};

class Asteroid
{
public:
	Asteroid(GameDataRef data);

	void SpawnAsteroid();

	void MoveAsteroids(float dt);
	void MoveExplosions(float dt);

	void DrawAsteroids();
	void DrawExplosions();

	void RandomiseAsteroidOffset();
	void DeleteAsteroid(int index);
	void DestroyAsteroid(int index);

	const std::vector<AsteroidSprite>& GetSprites() const;

private:
	GameDataRef _data;

	std::vector<AsteroidSprite> asteroidSprites;
	std::vector<ExplosionSprite> explosionSprites;

	std::vector<sf::Texture> animationFrames;

	int _spaceWidth;
	int _spaceHeight;
	int _asteroidSpawnXOffset;

	float _randomDirection;

};
