#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"
#include "GameState.hpp"

#include <iostream>
#include <fstream>


GameOverState::GameOverState(GameDataRef data, int score) : _data(data), _score(score)
{

}

void GameOverState::Init()
{
    std::ifstream readFile;
    readFile.open("Resources/Highscore.txt");

    if (readFile.is_open())
    {
        while (!readFile.eof())
        {
            readFile >> _highScore;
        }
    }

    readFile.close();

    std::ofstream writeFile("Resources/Highscore.txt");

    if (writeFile.is_open())
    {
        if (_score > _highScore)
        {
            _highScore = _score;
        }

        writeFile << _highScore;
    }

    writeFile.close();

    this->_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);

    _background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
    _retryButton.setTexture(this->_data->assets.GetTexture("Play Button"));

    _retryButton.setPosition((SCREEN_WIDTH / 2) - (_retryButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_retryButton.getGlobalBounds().height / 2));

    _scoreText.setFont(this->_data->assets.GetFont("Castelar Font"));
    _scoreText.setString("Your score: " + std::to_string(_score));
    _scoreText.setCharacterSize(20);
    _scoreText.setFillColor(sf::Color::White);
    _scoreText.setOrigin(sf::Vector2f(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2));
    _scoreText.setPosition(sf::Vector2f(245, _data->window.getSize().y / 1.45));

    _highScoreText.setFont(this->_data->assets.GetFont("Castelar Font"));
    _highScoreText.setString("Highest score: " + std::to_string(_highScore));
    _highScoreText.setCharacterSize(20);
    _highScoreText.setFillColor(sf::Color::White);
    _highScoreText.setOrigin(sf::Vector2f(_highScoreText.getGlobalBounds().width / 2, _highScoreText.getGlobalBounds().height / 2));
    _highScoreText.setPosition(sf::Vector2f(245, _data->window.getSize().y / 1.25));
}

void GameOverState::HandleInput()
{
    sf::Event event;

    while (this->_data->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            this->_data->window.close();
        }

        if (this->_data->input.IsSpriteClicked(this->_retryButton, sf::Mouse::Left, this->_data->window))
        {
            this->_data->machine.AddState(StateRef(new GameState(_data)), true);
        }
    }
}

void GameOverState::Update(float dt)
{

}

void GameOverState::Draw(float dt)
{
    this->_data->window.clear(sf::Color::Red);

    this->_data->window.draw(this->_background);

    _data->window.draw(_retryButton);
    _data->window.draw(_scoreText);
    _data->window.draw(_highScoreText);

    this->_data->window.display();
}
