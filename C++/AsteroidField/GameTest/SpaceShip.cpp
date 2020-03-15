#include "SpaceShip.hpp"

SpaceShip::SpaceShip(GameDataRef data) : _data(data)
{
	_animationFrames.push_back(this->_data->assets.GetTexture("Ship main"));
	_animationFrames.push_back(this->_data->assets.GetTexture("Ship turning left"));
	_animationFrames.push_back(this->_data->assets.GetTexture("Ship turning right"));

	_shipSprite.setTexture(_animationFrames[0]);

	_shipSprite.setPosition( (_data->window.getSize().x/2), (_data->window.getSize().y - _shipSprite.getGlobalBounds().height/2) );

	_shipState = SHIP_STATE_MAIN;

	sf::Vector2f origin = sf::Vector2f(_shipSprite.getGlobalBounds().width / 2, _shipSprite.getGlobalBounds().height / 2);

	_shipSprite.setOrigin(origin);

	_spaceShipMass = SPACESHIP_MASS;

	if (_spaceShipMass > 0)
	{
		_spaceShipAcceleration = SPACESHIP_MANOEUVERING_ENGINES_THRUST / _spaceShipMass;
	}
	else if (_spaceShipMass == 0)
	{
		log << "Are you sure that spaceship should have 0kg mass?";
		_spaceShipAcceleration = SPACESHIP_MANOEUVERING_ENGINES_THRUST;
	}
	else
	{
		log << "Are you sure that spaceship should have negative mass?";
		_spaceShipAcceleration = 0.001f;
	}

}

SpaceShip::~SpaceShip()
{
	log << "WARN: class destructor was called.";
}

void SpaceShip::Draw()
{
	_data->window.draw(_shipSprite);
}

void SpaceShip::Update(float dt)
{

	if (SHIP_STATE_TURNING_LEFT == _shipState)
	{
		_shipSprite.setTexture(_data->assets.GetTexture("Ship turning left"));
		if (_shipSprite.getPosition().x > 0 + _shipSprite.getGlobalBounds().width / 2)
		{
			_shipSprite.move(-_spaceShipAcceleration, 0);
		}
	}
	else if (SHIP_STATE_TURNING_RIGHT == _shipState)
	{
		_shipSprite.setTexture(_data->assets.GetTexture("Ship turning right"));
		if (_shipSprite.getPosition().x < SCREEN_WIDTH - _shipSprite.getGlobalBounds().width/2)
		{
			_shipSprite.move(_spaceShipAcceleration, 0);
		}
	}
	else if (SHIP_STATE_MAIN == _shipState)
	{
		_shipSprite.setTexture(_data->assets.GetTexture("Ship main"));
	}

}

void SpaceShip::PressKey()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		_shipState = SHIP_STATE_TURNING_LEFT;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		_shipState = SHIP_STATE_TURNING_RIGHT;
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		_shipState = SHIP_STATE_MAIN;
	}
}

const sf::Sprite& SpaceShip::GetSprite() const
{
	return _shipSprite;
}
