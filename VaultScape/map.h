#pragma once
#include "image.h"
#include "VaultScape.h"
#include <vector>
#include "fileIO.h"


namespace MapNS
{
	const int TILE_SIZE = 96;
}

class Map 
{
public:
	Map();
	//Map(VaultScape v);
	~Map();

	void loadMap(std::string fileName);
	void loadMap(int arr[6][5]);
	void drawMap(VaultScape* v);
	 
private:
	Image tile;
	int map[6][5];
	std::vector<std::vector<int>> map2;
};