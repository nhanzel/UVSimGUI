#include "File.h"

File::File() {

}

void File::New() {

}

std::string File::Load() {
	std::string content;
	std::string contents;

	inputData.open(filePath);

	while (!inputData.eof()) {
		inputData >> content;
		contents += content;
		contents += "\r\n";
	}

	inputData.close();

	return contents;
}

bool File::Save(std::string _s) {

	outputData.open(filePath);

	//checks if the file opened correctly
	//and checks if the input went smoothly
	if (outputData.good()) {
		if (outputData << _s) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
	outputData.close();
}

void File::setFilePath(std::string _s) {
	filePath = _s + ".txt";
}