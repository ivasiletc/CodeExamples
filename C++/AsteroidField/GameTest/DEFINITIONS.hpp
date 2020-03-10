#pragma once

/*   Game settings   */
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 800

#define SPLASH_STATE_SHOW_TIME 3.0

#define SPACE_MOVEMENT_SPEED 20.0f
/*   #############   */




/*   Textures path   */
#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resource Files/background1.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "Resource Files/background3.png"
#define GAME_TITLE_FILEPATH "Resource Files/background2.png"
#define PLAY_BUTTON_FILEPATH "Resource Files/background1.png"
/*   #############   */

enum GameStates
{
	eReady,
	ePlaying,
	eGameOver
};