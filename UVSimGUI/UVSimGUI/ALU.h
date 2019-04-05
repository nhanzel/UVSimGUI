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

	ALU();

	//arithmetic functions
	int add(int, int);

	int subtract(int, int);

	int multiply(int, int);

	int divide(int, int);

	int exponent(int, int);

	int remainder(int, int);
	//end of arithmetic functions

	//getters and setters
	int getInstr();

	void setInstr(int);

	int getCount();

	void setCount(int);

	int getLocation();

	void setLocation(int);

	int getAccu();

	void setAccu(int);
	//end of getters and setters

	//reading and writing
	int read();

	System::String^ write(int, int);
	//end of reading and writing

	~ALU();
};

