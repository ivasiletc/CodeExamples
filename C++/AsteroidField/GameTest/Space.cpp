#include "Space.hpp"
#include "DEFINITIONS.hpp"

Space::Space(GameDataRef data) : _data(data)
{
	sf::Sprite sprite(this->_data->assets.GetTexture("Space"));
	sf::Sprite sprite2(this->_data->assets.GetTexture("Space"));

	sprite.setPosition(0, this->_data->window.getSize().y - sprite.getLocalBounds().height);
	sprite2.setPosition(sprite.getLocalBounds().width, this->_data->window.getSize().y - sprite2.getLocalBounds().height);

	_spaceSprites.push_back(sprite);
	_spaceSprites.push_back(sprite2);
}

void Space::MoveSpace(float dt)
{
	for (unsigned short int i = 0; i < _spaceSprites.size(); i++)
	{
		sf::Vector2f position = _spaceSprites.at(i).getPosition();
		float movement = SPACE_MOVEMENT_SPEED * dt;

		_spaceSprites.at(i).move(-movement, 0.0f);

		if (_spaceSprites.at(i).getPosition().x < 0 - _spaceSprites.at(i).getLocalBounds().width)
		{
			sf::Vector2f position(_data->window.getSize().x, _spaceSprites.at(i).getPosition().y);

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