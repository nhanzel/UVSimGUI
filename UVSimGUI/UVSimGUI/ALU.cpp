#include "ALU.h"

ALU::ALU() {

	accumulator = 0;
	instruction = 0;
	location = 0;
	input = 0;
	count = 0;
	instCount = 0;

}

void ALU::updateIns(int i, int lineNum) {
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

int ALU::exponent(int accumulator, int value) {
	int ans = 1;
	for (int i = 0; i < value; i++) {
		ans = multiply(ans, accumulator);
	}
	return ans;
}

int ALU::remainder(int accumulator, int value) {
	int i = 1;
	int prod = 0;
	while (prod <= accumulator) {
		prod = value * i;
		i++;
	}
	return accumulator - (prod - value);
}

int ALU::getInstr() {
	return instruction;
}

void ALU::setInstr(int _i) {
	instruction = _i;
}

int ALU::getCount() {
	return count;
}

void ALU::setCount(int _c) {
	count = _c;
}

int ALU::getLocation() {
	return location;
}

void ALU::setLocation(int _l) {
	location = _l;
}

int ALU::getAccu() {
	return accumulator;
}

void ALU::setAccu(int _a) {
	accumulator = _a;
}

int ALU::read() {
	return 5;
}

System::String^ ALU::write(int location, int value) {
	return "The value stored at location " + location + " is " + value;
}

ALU::~ALU() {}