#include "ALU.h"

ALU::ALU() {

	accumulator = 0;
	instruction = 0;
	location = 0;
	input = 0;
	count = 0;
	instCount = 0;

}

void ALU::updateIns(std::string i, int lineNum) {
	memory[lineNum] = i;
}

int ALU::add(int accumulator, int value) {
	return accumulator + value;
}

int ALU::subtract(int accumulator, int value) {
	return add(accumulator, (0 - value));
}

int ALU::multiply(int accumulator, int value) {
	//cout << accumulator << " * " << value << endl;
	int total = 0;
	for (int i = 0; i < value; ++i) {
		total = (add(total, accumulator));
	}
	return total;
}

int ALU::divide(int accumulator, int value) {
	//cout << "dividing" << endl;
	int i = 0;
	int remainder = accumulator;
	while (remainder >= value)
	{
		//cout << "remainder: " << remainder << "\t" << i << endl;
		remainder = subtract(remainder, value);
		i++;
	}
	return i;
}

ALU::~ALU() {}