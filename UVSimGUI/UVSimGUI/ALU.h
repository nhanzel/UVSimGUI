#include <string>
#pragma once

class ALU
{
private:

	signed int accumulator;
	int instruction;
	int location;
	int input;
	int count;
	int instCount;

public:

	std::string memory[1000] = {};

	ALU();

	void updateIns(std::string, int);

	//arithmetic functions
	int add(int, int);

	int subtract(int, int);

	int multiply(int, int);

	int divide(int, int);
	//end of arithmetic functions

	int getInstr();

	void setInstr(int);

	int getCount();

	void setCount(int);

	int getLocation();

	void setLocation(int);

	int getAccu();

	void setAccu(int);


	~ALU();

};
