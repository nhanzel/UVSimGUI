#include "ALU.h"

ALU::ALU() {

	accumulator = 0;
	instruction = 0;
	location = 0;
	input = 0;
	count = 0;
	instCount = 0;

}

int ALU::add(int accumulator, int value) {
	if (value == 0) {
		return accumulator;
	}
	else {
		return add(accumulator^value, (accumulator & value) << 1);
	}
}

int ALU::subtract(int accumulator, int value) {
	if (value == 0) {
		return accumulator;
	}
	else {
		return subtract(accumulator^value, (~accumulator & value) << 1);
	}
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
	int result = 1;
	while (value != 0) {
		result *= accumulator;
		--value;
	}
	return result;
}

int ALU::remainder(int accumulator, int value) {
	if (value == 0) {
		return accumulator;
	}
	return accumulator % value;
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

System::String^ ALU::write(int value, int location) {
	//\r\n is a newline character
	return "The value stored at location " + location + " is " + value + "\r\n" + "\r\n";
}

ALU::~ALU() {}