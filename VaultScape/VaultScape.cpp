//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#include "VaultScape.h"
#include "gameState.h"
#include "mainMenuState.h"

#include "buttons.h"
#include "map.h"


VaultScape::VaultScape()
{
	buttonFont = new TextDX();
}

VaultScape::~VaultScape()
{
	releaseAll();
}


void VaultScape::initialize(HWND hwnd)
{
	
	Game::initialize(hwnd); // throws GameError
	time_t t;
	srand(time(&t));

	// Initialize Texture
	if (!backgroundMainMenuTexture.initialize(graphics, MAIN_MENU_SCREEN))
		throw(GameError(gameErrorNS::FATAL_ERROR,
			"Error initializing main menu texture"));

	if (!backgroundPausedTexture.initialize(graphics, PAUSED_SCREEN))
		throw(GameError(gameErrorNS::FATAL_ERROR,
			"Error initializing pause texture"));

	if (!mapTexture.initialize(graphics, MAP_SPRITES))
		throw(GameError(gameErrorNS::FATAL_ERROR,
			"Error initializing main menu texture"));


	if (!buttonTexture.initialize(graphics, BUTTON_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR,
			"Error initializing button texture"));
	
	// Initialize Images
	if (!backgroundMainMenu.initialize(graphics, GAME_WIDTH, GAME_HEIGHT, 0, &backgroundMainMenuTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR,
			"Error initializing main menu"));

	if (!backgroundPaused.initialize(graphics, GAME_WIDTH, GAME_HEIGHT, 0, &backgroundPausedTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR,
			"Error initializing pause"));

	if (!tileSprites.initialize(graphics, MapNS::TILE_SIZE, MapNS::TILE_SIZE, 4, &mapTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR,
			"Error initializing map sprites"));


	if (!buttonImage.initialize(graphics, ButtonNS::BUTTON_WIDTH, ButtonNS::BUTTON_HEIGHT, ButtonNS::BUTTON_NCOLS, &buttonTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR,
			"Error initializing button"));



	// Initialize Fonts
	if (buttonFont->initialize(graphics, 24, false, false, "Intro Rust G Base 2 Line") == false)
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font"));


	// Initialize Initial Game State
	currentState.push_back(new  MainMenuState());
	currentState.back()->entry(this);
	
}

void VaultScape::handleInput()
{
	currentState.back()->handleInput(this, input);
}

void VaultScape::update()
{
	currentState.back()->update(this);
}
void VaultScape::ai()
{ 
	currentState.back()->ai(this);
}

void VaultScape::collisions()
{
	currentState.back()->collisions(this);
}

void VaultScape::render()
{
	// Begin Drawing Sprites
	graphics->beginScene();

	graphics->spriteBegin();

	// Rendering sprites
	// Add drawing/rendering of sprites here
	currentState.back()->render(this);

	// End Drawing Sprites
	graphics->spriteEnd();
	graphics->endScene();
	graphics->showBackbuffer();
	
}

void VaultScape::releaseAll()
{
	Game::releaseAll();
	return;
}

void VaultScape::resetAll()
{
	Game::resetAll();
	return;
}
