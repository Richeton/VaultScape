#include "runningState.h"
#include "pausedState.h"

void RunningState::entry(VaultScape * game)
{	
		map.loadMap("lv1.txt");

	//MessageBox(NULL, a.c_str(), "0", 0);
	
}

void RunningState::handleInput(VaultScape * game, Input * input)
{

	float testX;
	
	if (input->isKeyDown(VK_ESCAPE))
	{
		this->exit(game);
		game->currentState.push_back(new  PausedState);
		game->currentState.back()->entry(game);
		input->clearAll();
	}

	/*
	// player.handleInput(Input * input);

	if (input->isKeyDown(VK_DOWN))
	{
		mapY -= 1 * game->scale;
	}
	if (input->isKeyDown(VK_UP))
	{
		mapY += 1 * game->scale;
	}
	if (input->isKeyDown(VK_LEFT))
	{
		mapX += 1 * game->scale;
	}
	if (input->isKeyDown(VK_RIGHT))
	{
		mapX -= 1 * game->scale;
	}

	if (input->isKeyDown(VK_SPACE))
	{
		game->scale -= 0.01;
	}

	if (input->isKeyDown(ALT_KEY))
	{
		game->scale += 0.01;
	}
	*/
}

void RunningState::update(VaultScape * game)
{
	//if (mapX > 0)
	//	mapX = 0;

	//if (mapX < (-bitmapNS::MAP_WIDTH*bitmapNS::TEXTURE_SIZE * game->scale) + int(GAME_WIDTH))
	//	mapX = (-bitmapNS::MAP_WIDTH*bitmapNS::TEXTURE_SIZE* game->scale) + int(GAME_WIDTH);

	//if (mapY > 0)
	//	mapY = 0;

	//if (mapY < (-bitmapNS::MAP_HEIGHT*bitmapNS::TEXTURE_SIZE* game->scale) + int(GAME_HEIGHT))
	//	mapY = (-bitmapNS::MAP_HEIGHT*bitmapNS::TEXTURE_SIZE* game->scale) + int(GAME_HEIGHT);

	//if (game->scale <= 1)
	//{
	//	game->scale = 1;
	//}

	//if (game->scale >= 2.5)
	//{
	//	game->scale = 2.5;
	//}
}

void RunningState::ai(VaultScape * game)
{
}

void RunningState::collisions(VaultScape * game)
{
}

void RunningState::render(VaultScape * game)
{
	map.drawMap(game);
}

void RunningState::exit(VaultScape * game)
{
	//MessageBox(NULL, "I HAVE LEFT RUNNING", "0", 0);
}
