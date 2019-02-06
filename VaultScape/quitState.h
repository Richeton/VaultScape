#ifndef _QUITSTATE_H                 // Prevent multiple definitions if this 
#define _QUITSTATE_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "gameState.h"

class QuitState :public GameState
{
public:
	virtual void entry(VaultScape * game);

	virtual void handleInput(VaultScape * game, Input * input) {}
	virtual void update(VaultScape * game) {}
	virtual void ai(VaultScape * game) {}
	virtual void collisions(VaultScape * game) {}
	virtual void render(VaultScape * game) {}

	virtual void exit(VaultScape * game) {}

};

#endif
