#include "HUD.hpp"

HUD::HUD(GameDataRef data) : _data(data)
{
	_scoreText.setFont(this->_data->assets.GetFont("Castelar Font"));

	_scoreText.setString("0");

	_scoreText.setCharacterSize(20);

	_scoreText.setFillColor(sf::Color::White);

	_scoreText.setPosition(sf::Vector2f(0, 0));
}

HUD::~HUD()
{
}

void HUD::Draw()
{
	_data->window.draw(_scoreText);
}

void HUD::UpdateScore(int score)
{
	_scoreText.setString(std::to_string(score));
}