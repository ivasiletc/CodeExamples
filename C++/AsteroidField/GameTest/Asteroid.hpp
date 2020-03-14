#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

class Asteroid
{
public:
	Asteroid(GameDataRef data);

	void SpawnAsteroid();

	void MoveAsteroids(float dt);
	void DrawAsteroids();
	void RandomiseAsteroidOffset();
	void DeleteAsteroid(int index);

	const std::vector<sf::Sprite>& GetSprites() const;

private:
	GameDataRef _data;
	std::vector<sf::Sprite> asteroidSprites;

	int _spaceWidth;
	int _spaceHeight;
	int _asteroidSpawnXOffset;
};
