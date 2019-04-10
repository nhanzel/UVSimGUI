#include <string>
#include <fstream>
#pragma once

using namespace std;

ref class File
{
private:
	string* filePath;
	ifstream* inputData;
	ofstream* outputData;

public:
	File();

	void New();

	string Load();

	bool Save(string, string);
};

