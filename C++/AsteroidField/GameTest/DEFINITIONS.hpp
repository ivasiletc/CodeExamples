#pragma once

/*   Game settings   */
#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 700

#define SPLASH_STATE_SHOW_TIME 3.0

#define SPACE_MOVEMENT_SPEED 20.0f

#define ASTEROID_MOVEMENT_SPEED 2.0f
/*   #############   */
#define ROTATION_SPEED 100.0f

#define ASTEROID_SPAWN_FREQUENCY 1.5f

/*   Textures path   */
#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/SplashState.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/background3.png"
#define GAME_TITLE_FILEPATH "Resources/title.png"
#define PLAY_BUTTON_FILEPATH "Resources/PlayButton.png"
#define GAME_BACKGROUND_FILEPATH "Resources/background1.png"
#define SPACE_FILEPATH "Resources/background2.png"

#define SHIP_LEFT_FILEPATH "Resources/ship_left.png"
#define SHIP_RIGHT_FILEPATH "Resources/ship_main.png"
#define SHIP_MAIN_FILEPATH "Resources/ship_right.png"

/*   #############   */

#define SHIP_STATE_MAIN 1
#define SHIP_STATE_TURNING_LEFT 2
#define SHIP_STATE_TURNING_RIGHT 3

enum GameStates
{
	eReady,
	ePlaying,
	eGameOver
};