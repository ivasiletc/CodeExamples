#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"

class MainMenuState : public State
{
public:
    MainMenuState(GameDataRef data);

    void Init();

    void HandleInput() override;
    void Update(float dt) override;
    void Draw(float dt) override;

private:
    GameDataRef _data;

    sf::Sprite _background;
    sf::Sprite _title;
    sf::Sprite _playButton;
};
