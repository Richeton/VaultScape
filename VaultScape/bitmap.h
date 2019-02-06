#ifndef _BITMAP_H
#define _BITMAP_H
#define WIN32_LEAN_AND_MEAN

#include <string>
#include "fileIO.h"

namespace bitmapNS
{
	const std::string FILE_NAME = "bitmap2.txt";

	const int TEXTURE_SIZE = 96;
	const int TEXTURE_COLS = 4;
	const int MAP_HEIGHT = 10;
	const int MAP_WIDTH = 23;
	const float SCROLL_RATE = 10;
	const int __ = -1;                  // empty tile

	const int tileMap[MAP_HEIGHT][MAP_WIDTH] = 
	{
24,	4,	4,	4,	4,	4,	4,	4,	27,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,
8,	0,	0,	0,	0,	0,	0,	0,	12,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,
8,	0,	0,	0,	0,	0,	0,	0,	12,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,
8,	0,	0,	0,	0,	0,	0,	0,	12,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,
25,	16,	16,	20,	0,	23,	16,	16,	26,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,	__,
24,	4,	4,	21,	0,	22,	4,	4,	27,	__,	__,	__,	__,	__,	24,	4,	4,	4,	4,	4,	4,	4,	27,
8,	0,	0,	0,	0,	0,	0,	0,	22,	4,	4,	4,	4,	4,	21,	0,	0,	0,	0,	0,	0,	0,	12,
8,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	12,
8,	0,	0,	0,	0,	0,	0,	0,	23,	16,	16,	16,	16,	16,	20,	0,	0,	0,	0,	0,	0,	0,	12,
25,	16,	16,	16,	16,	16,	16,	16,	26,	__,	__,	__,	__,	__,	25,	16,	16,	16,	16,	16,	16,	16,	26
	};
}

class BitMap
{
private:
	std::string fileName = bitmapNS::FILE_NAME;
	
public:
	std::string getBitmap();

	
};

#endif 
