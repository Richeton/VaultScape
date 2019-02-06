#include "bitmap.h"

std::string BitMap::getBitmap()
{
	FileIO file = FileIO();
	std::string bitmap = file.readFile(this->fileName);

	return bitmap;
}
