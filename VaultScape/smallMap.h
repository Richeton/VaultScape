#ifndef _SMALLMAP_H
#define _SMALLMAP_H
#define WIN32_LEAN_AND_MEAN

#include <string>
#include "fileIO.h"



class SmallMap
{
private:	
	int mapWidth;
	int mapHeight; 
	
	int *ary = new int[mapWidth*mapHeight];

	// ary[i][j] is then rewritten as
//	ary[i*sizeY + j]

public:
	void makeSmallMap() 
	{

		int **ary = new int*[mapHeight];
		for (int i = 0; i < mapHeight; ++i) {
			ary[i] = new int[mapWidth];
		}
	}

};

#endif 
