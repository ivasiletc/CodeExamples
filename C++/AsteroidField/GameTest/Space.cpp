#include "Space.hpp"
#include "DEFINITIONS.hpp"

Space::Space(GameDataRef data) : _data(data)
{
	sf::Sprite sprite(this->_data->assets.GetTexture("Space"));
    sf::Sprite sprite2(this->_data->assets.GetTexture("Space"));

	sprite.setPosition(0, this->_data->window.getSize().y - sprite.getLocalBounds().height);
	sprite2.setPosition(0, sprite2.getLocalBounds().height);

	_spaceSprites.push_back(sprite);
	_spaceSprites.push_back(sprite2);
}

void Space::MoveSpace(float dt)
{
	for (unsigned short int i = 0; i < _spaceSprites.size(); i++)
	{
		sf::Vector2f position = _spaceSprites.at(i).getPosition();
		float movement = SPACESHIP_FORWARD_MOVEMENT_SPEED * dt;

		_spaceSprites.at(i).move(0.0f, movement);

		if (_spaceSprites.at(i).getPosition().y > 0)
		{
			sf::Vector2f position(0, this->_data->window.getSize().y - _spaceSprites.at(i).getLocalBounds().height);

			_spaceSprites.at(i).setPosition(position);
		}
	}
}

void Space::DrawSpace()
{
	for (unsigned short int i = 0; i < _spaceSprites.size(); i++)
	{
		this->_data->window.draw(_spaceSprites.at(i));
	}
}

const std::vector<sf::Sprite>& Space::GetSprites() const
{
	return _spaceSprites;
}