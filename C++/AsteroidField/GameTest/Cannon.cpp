#include "Cannon.hpp"

Cannon::Cannon(GameDataRef data) : _data(data)
{

}

void Cannon::Shoot(int x, int y)
{
	sf::Sprite sprite(this->_data->assets.GetTexture("Bullet"));

	sprite.setPosition(x, y);

	bulletSprites.push_back(sprite);
}

void Cannon::Draw()
{
	for (unsigned short int i = 0; i < bulletSprites.size(); i++)
	{
		this->_data->window.draw(bulletSprites.at(i));
	}
}

void Cannon::Update(float dt)
{
	for (int i = 0; i < bulletSprites.size(); i++)
	{
		if (bulletSprites.at(i).getPosition().y < 0)
		{
			bulletSprites.erase(bulletSprites.begin() + i);
		}
		else
		{
			sf::Vector2f position = bulletSprites.at(i).getPosition();
			float movement = (SPACESHIP_FORWARD_MOVEMENT_SPEED + CANNON_BULLETS_SPEED) * dt;

			bulletSprites.at(i).move(0, -movement);
		}
	}
}

const std::vector<sf::Sprite>& Cannon::GetSprite() const
{
    return bulletSprites;
}
