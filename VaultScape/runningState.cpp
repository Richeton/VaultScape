#include "runningState.h"
#include "pausedState.h"

void RunningState::entry(VaultScape * game)
{
	std::string a = bitmap.getBitmap();
	
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

	// player.handleInput(Input * input);

	if (input->isKeyDown(VK_DOWN))
	{
		mapY -= 1;
	}
	if (input->isKeyDown(VK_UP))
	{
		mapY += 1;
	}
	if (input->isKeyDown(VK_LEFT))
	{
		mapX += 1;
	}
	if (input->isKeyDown(VK_RIGHT))
	{
		mapX -= 1;
	}
}

void RunningState::update(VaultScape * game)
{
	if (mapX > 0)
		mapX = 0;

	if (mapX < (-bitmapNS::MAP_WIDTH*bitmapNS::TEXTURE_SIZE) + int(GAME_WIDTH))
		mapX = (-bitmapNS::MAP_WIDTH*bitmapNS::TEXTURE_SIZE) + int(GAME_WIDTH);

	if (mapY > 0)
		mapY = 0;

	if (mapY < (-bitmapNS::MAP_HEIGHT*bitmapNS::TEXTURE_SIZE) + int(GAME_HEIGHT))
		mapY = (-bitmapNS::MAP_HEIGHT*bitmapNS::TEXTURE_SIZE) + int(GAME_HEIGHT);
}

void RunningState::ai(VaultScape * game)
{
}

void RunningState::collisions(VaultScape * game)
{
}

void RunningState::render(VaultScape * game)
{
	// renderMap();
	tile = game->map;

	for (int row = 0; row < bitmapNS::MAP_HEIGHT; row++)       // for each row of map
	{
		tile.setY((float)(row*bitmapNS::TEXTURE_SIZE) + mapY); // set tile Y
		for (int col = 0; col < bitmapNS::MAP_WIDTH; col++)    // for each column of map
		{
			if (bitmapNS::tileMap[row][col] >= 0)          // if tile present
			{
				tile.setCurrentFrame(bitmapNS::tileMap[row][col]);    // set tile texture
				tile.setX((float)(col*bitmapNS::TEXTURE_SIZE) + mapX);   // set tile X
				
				// if tile on screen
				if (tile.getX() > -bitmapNS::TEXTURE_SIZE && tile.getX() < GAME_WIDTH)
					tile.draw();                // draw tile
			}
		}
	}

}

void RunningState::exit(VaultScape * game)
{
	//MessageBox(NULL, "I HAVE LEFT RUNNING", "0", 0);
}
