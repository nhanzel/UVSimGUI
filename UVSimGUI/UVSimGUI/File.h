#pragma once
#include <string>
#include <iostream>
#include <fstream>

class File
{
private:
	std::string filePath;
	std::ifstream inputData;
	std::ofstream outputData;
public:
	File();

	void New();

	std::string Load();

	bool Save(std::string);

	void setFilePath(std::string);

	~File();
};