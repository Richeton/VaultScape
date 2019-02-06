#include "fileIO.h"
#include <fstream>
#include <iostream>


std::string FileIO::readFile(std::string fileName)
{
	if (createFile(fileName) != "")
		return "File cannot be created";
	std::ifstream file(fileName);
	std::string string;
	std::string file_contents;
	while (std::getline(file, string))
	{
		// Process str
		file_contents += string;
	}
	return file_contents;
}

std::string FileIO::addToFile(std::string fileName, std::string string)
{
	std::ofstream file;
	file.open(fileName, std::ios_base::app);
	file << string;
	return string;
}

void FileIO::clearFile(std::string fileName)
{
	std::ofstream file;
	file.open(fileName, std::ofstream::out | std::ofstream::trunc);
	file.close();
}

std::string FileIO::createFile(std::string fileName)
{
	if (!std::ifstream(fileName))
	{
		std::ofstream file(fileName);
		if (!file)
		{
			return "File cannot be Created";
		}
	}
	return "";
}