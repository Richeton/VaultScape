#ifndef _RUNNINGSTATE_H                 // Prevent multiple definitions if this 
#define _RUNNINGSTATE_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "gameState.h"
#include "bitmap.h"

class RunningState :public GameState
{
public:


	virtual void entry(VaultScape * game);

	virtual void handleInput(VaultScape * game, Input * input);
	virtual void update(VaultScape * game);
	virtual void ai(VaultScape * game);
	virtual void collisions(VaultScape * game);
	virtual void render(VaultScape * game);

	virtual void exit(VaultScape * game);

private:
	std::vector<Button> buttonList;
	BitMap bitmap;
	float mapX;
	float mapY;
	Image tile;
};
#endif