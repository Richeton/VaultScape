//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#ifndef _VAULTSCAPE_H
#define _VAULTSCAPE_H
#define WIN32_LEAN_AND_MEAN

#include "game.h"
#include "buttons.h"
#include "image.h"
#include "textureManager.h"
#include "textDX.h"

#include <ctime>
#include <algorithm>
#include <vector>

class GameState;


class VaultScape : public Game
{
private:
	TextureManager backgroundMainMenuTexture;
	TextureManager backgroundPausedTexture;
	TextureManager buttonTexture;
	TextureManager mapTexture;
public:
	// Constructor
	VaultScape();
	// Destructor
	virtual ~VaultScape();

	// Initialize the Game
	void initialize(HWND hwnd);

	void handleInput();

	// Updates the Game
	void update();

	// Handles AI
	void ai();

	// Handles collisions
	void collisions();

	// Handles renders
	void render();

	// Releases all reserved video memory
	void releaseAll();

	// Resets all surfaces
	void resetAll();

	std::vector<GameState *> currentState;

	Image backgroundMainMenu;
	Image backgroundPaused;
	Image buttonImage;
	Image map;
	TextDX * buttonFont;

	float scale = 1.5;

};
#endif