#ifndef _GAMESTATE_H                 // Prevent multiple definitions if this 
#define _GAMESTATE_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "input.h"
#include "VaultScape.h"
#include "buttons.h"
#include "image.h"
#include <vector>

class MainMenuState;
class RunningState;
class PausedState;

class GameState
{
public:	
	virtual ~GameState() {};
	
	virtual void entry(VaultScape * game) = 0;

	virtual void handleInput(VaultScape * game, Input * input) = 0;

	virtual void update(VaultScape * game) = 0;
	virtual void ai(VaultScape * game) = 0;
	virtual void collisions(VaultScape * game) = 0;
	virtual void render(VaultScape * game) = 0;

	virtual void exit(VaultScape * game) = 0;

	std::vector<Button> buttonList;
	
private:
};
#endif