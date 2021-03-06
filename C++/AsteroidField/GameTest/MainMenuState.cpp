#pragma once

#include <sstream>
#include <iostream>

#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"
#include "GameState.hpp"

MainMenuState::MainMenuState(GameDataRef data) : _data(data)
{

}

void MainMenuState::Init()
{
    _data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
    _data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);

    _background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
    _playButton.setTexture(this->_data->assets.GetTexture("Play Button"));

    _playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2));
}

void MainMenuState::HandleInput()
{
    sf::Event event;

    while (_data->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            _data->window.close();
        }

        if (this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            // Switch To Game
            this->_data->machine.AddState(StateRef(new GameState(_data)), true);
        }
    }
}

void MainMenuState::Update(float dt)
{

}

void MainMenuState::Draw(float dt)
{
    _data->window.clear();

    _data->window.draw(_background);
    _data->window.draw(this->_title);
    _data->window.draw(this->_playButton);

    _data->window.display();
}