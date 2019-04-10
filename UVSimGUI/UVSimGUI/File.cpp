#include "File.h"

File::File() {

}

void File::New() {
	//TODO: User specifies the file
}

string File::Load() {
	string* contents;

	//TODO: User specifies the file

	inputData->open(*filePath);

	*inputData >> *contents;

	return *contents;
}

bool File::Save(string _s, string _f) {
	if (_f != "") {
		*filePath = _f;
	}

	outputData->open(*filePath);

	//checks if the file opened correctly
	//and checks if the input went smoothly
	if (outputData->good()) {
		if (*outputData << _s) {
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}

	outputData->close();
}
