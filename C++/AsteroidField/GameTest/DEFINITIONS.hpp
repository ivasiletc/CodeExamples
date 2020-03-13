#pragma once

/*   Game settings   */
#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 700

#define SPLASH_STATE_SHOW_TIME 0.1

#define SPACESHIP_FORWARD_MOVEMENT_SPEED 50.0f
#define SPACESHIP_MANOEUVERING_ENGINES_THRUST 1
#define SPACESHIP_MASS 1

/* Spawn an object (asteroid/bullet) every $value seconds. Less $value ->  frequency increases*/
#define CANNON_SHOOTING_FREQUENCY 1.0f
#define ASTEROID_SPAWN_FREQUENCY 1.5f

#define CANNON_BULLETS_SPEED 10

#define ASTEROID_ANGULAR_RANGE 2
#define ASTEROID_EXPLOSION_DURATION 4
#define ASTEROID_MOVEMENT_SPEED 100.0f
#define ASTEROID_SPAWN_FREQUENCY_INCREASING 0.5f

/*   #############   */

/*   Textures path   */
#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/SplashState.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/background1.png"
#define GAME_BACKGROUND_FILEPATH "Resources/background1.png"

#define SPACE_FILEPATH "Resources/background1.png"

#define PLAY_BUTTON_FILEPATH "Resources/PlayButton.png"

#define BULLET_FILEPATH "Resources/bullet.png"

#define SHIP_LEFT_FILEPATH "Resources/ship_left.png"
#define SHIP_RIGHT_FILEPATH "Resources/ship_right.png"
#define SHIP_MAIN_FILEPATH "Resources/ship_main.png"

#define ASTEROID_TEXTURES_AMOUNT 4

#define ASTEROID0_FILEPATH "Resources/asteroid0.png"
#define ASTEROID1_FILEPATH "Resources/asteroid1.png"
#define ASTEROID2_FILEPATH "Resources/asteroid2.png"
#define ASTEROID3_FILEPATH "Resources/asteroid3.png"
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