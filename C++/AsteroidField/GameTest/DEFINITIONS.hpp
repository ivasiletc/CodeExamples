#pragma once

/*   Game settings   */
#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 700

#define SPLASH_STATE_SHOW_TIME 0.1

#define SPACESHIP_FORWARD_MOVEMENT_SPEED 50.0f
#define SPACESHIP_MANOEUVERING_ENGINES_THRUST 5.0f
#define SPACESHIP_MASS 0.0f

#define CANNON_SHOOTING_FREQUENCY 2.0f
#define CANNON_BULLETS_SPEED 10

#define ASTEROID_SPAWN_FREQUENCY 0.5f
#define ASTEROID_SPAWN_FREQUENCY_INCREASING 0.25f

#define ASTEROID_ANGULAR_RANGE 2
#define ASTEROID_EXPLOSION_DURATION 4
#define ASTEROID_MOVEMENT_SPEED 100.0f

#define ASTEROID_EXPLOSION_DURATION 1.0f

#define SCORE_INCREASING_TIME 1.0f
/*   #############   */

/*   Textures path   */
#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/SplashState.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/background1.png"
#define GAME_BACKGROUND_FILEPATH "Resources/background1.png"
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/GameOverState.png"

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

#define ASTEROID_EXPLOSION0_FILEPATH "Resources/AsteroidExplosion0.png"
#define ASTEROID_EXPLOSION1_FILEPATH "Resources/AsteroidExplosion1.png"
#define ASTEROID_EXPLOSION2_FILEPATH "Resources/AsteroidExplosion2.png"
#define ASTEROID_EXPLOSION3_FILEPATH "Resources/AsteroidExplosion3.png"
#define ASTEROID_EXPLOSION4_FILEPATH "Resources/AsteroidExplosion4.png"
#define ASTEROID_EXPLOSION5_FILEPATH "Resources/AsteroidExplosion5.png"
#define ASTEROID_EXPLOSION6_FILEPATH "Resources/AsteroidExplosion6.png"
#define ASTEROID_EXPLOSION7_FILEPATH "Resources/AsteroidExplosion7.png"
/*   #############   */

#define FONT_FILEPATH "Resources/CASTELAR.ttf"

#define SHIP_STATE_MAIN 1
#define SHIP_STATE_TURNING_LEFT 2
#define SHIP_STATE_TURNING_RIGHT 3

enum GameStates
{
	eReady,
	ePlaying,
	eGameOver
};