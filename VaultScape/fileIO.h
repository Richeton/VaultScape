#ifndef _FILEIO_H
#define _FILEIO_H
#define WIN32_LEAN_AND_MEAN

#include <string>

class FileIO
{
private:
public:
	std::string readFile(std::string fileName);
	std::string addToFile(std::string fileName, std::string string);
	void clearFile(std::string fileName);
	std::string createFile(std::string fileName);
};

#endif // !_FILEIO_H
