#include "map.h"
#include <iostream>
#include <string>

int lv1[6][5] =
{
	{0,0,1,0,0},
	{1,1,0,0,0},
	{0,0,0,0,0},
	{0,2,0,0,0},
	{0,2,0,0,0},
	{3,3,0,0,0}
};

Map::Map()
{
	loadMap(lv1);
}

Map::~Map()
{
}

void Map::loadMap(std::string fileName)
{
	std::vector<int> row;
	std::string strRow;
	FileIO file;
	std::string mapData;
	mapData = file.readFile(fileName);

	//firstRow = mapData.substr(0, mapData.find("}") + 1)



//	for (int columns = 0; columns <= 5; columns++)
	{
		// Finds index of { as the start of row and index of }+1 as the end of row
//		strRow = mapData.substr(mapData.find("{"), mapData.find("}") + 1);		// First Row
//		MessageBox(NULL, strRow.c_str(), 0, 0);


			while (strRow.length() > 0)
			{
				std::string rowCell = strRow.substr(0, mapData.find(",", 1) - 1);
				if (rowCell != "," && rowCell != "{" && rowCell != "}")
				{
					int tempInt = std::stoi(rowCell);

					row.push_back(tempInt);
					strRow.erase(0, 1);
					mapData.erase(0, 1);
				}
				strRow.erase(0, 1);
				mapData.erase(0, 1);
			}
			
			map2.push_back(row);

		
		
		row.clear();

	}

}

void Map::loadMap(int arr[6][5])
{ 

	for (int row = 0; row < 6; row++)
	{
		for (int column = 0; column < 5; column++) 
		{
			map[row][column] = arr[row][column];
		}
	}
}

void Map::drawMap(VaultScape* v)
{
	tile = v->tileSprites;

	int currentTile = 0;
	tile.setCurrentFrame(-1);

	for (int row = 0; row < 6; row++)
	{
		for (int column = 0; column < 5; column++)
		{
			currentTile = map[row][column];

			tile.setPosition(row * MapNS::TILE_SIZE, column * MapNS::TILE_SIZE);

			tile.setCurrentFrame(currentTile);
			tile.draw();

			/*
			switch (currentTile)
			{
			case 0:
				tile.setCurrentFrame(0);
				tile.draw();
				break;
			case 1:
				tile.setCurrentFrame(1);
				tile.draw();
				break;
			case 2:
				tile.setCurrentFrame(2);
				tile.draw();
				break;
			default:
				tile.setCurrentFrame(-1);
				tile.draw();
				break;
			}
			*/
		}
	}
}

