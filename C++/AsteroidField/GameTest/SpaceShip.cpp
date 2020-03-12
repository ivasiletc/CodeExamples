#include "SpaceShip.hpp"

SpaceShip::SpaceShip(GameDataRef data) : _data(data)
{
	_animationIterator = 0;

	_animationFrames.push_back(this->_data->assets.GetTexture("Ship turning left"));
	_animationFrames.push_back(this->_data->assets.GetTexture("Ship turning right"));
	_animationFrames.push_back(this->_data->assets.GetTexture("Ship main"));

	_shipSprite.setTexture(_animationFrames.at(_animationIterator));

	_shipSprite.setPosition((_data->window.getSize().x / 4) - (_shipSprite.getGlobalBounds().width / 2), (_data->window.getSize().y / 2) - (_shipSprite.getGlobalBounds().height / 2));

	_shipState = SHIP_STATE_MAIN;

	sf::Vector2f origin = sf::Vector2f(_shipSprite.getGlobalBounds().width / 2, _shipSprite.getGlobalBounds().height / 2);

	_shipSprite.setOrigin(origin);
}

SpaceShip::~SpaceShip()
{
	log << "WARN: class destructor was called.";
}

void SpaceShip::Draw()
{
	_data->window.draw(_shipSprite);
}

void SpaceShip::Animate(float dt)
{

}

void SpaceShip::Update(float dt)
{
	if (SHIP_STATE_TURNING_LEFT == _shipState)
	{
		log << "@TODO ship turning left functionality";
	}
	else if (SHIP_STATE_TURNING_RIGHT == _shipState)
	{
		log << "@TODO ship turning right functionality";
	}

	log << "@TODO ship coming back to normal state functionality";
}

const sf::Sprite& SpaceShip::GetSprite() const
{
	return _shipSprite;
}