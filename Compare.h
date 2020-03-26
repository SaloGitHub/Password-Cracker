#pragma once
#include "Task.h"
#include "Structs.h"
#include <iostream>

class CompareTask : public Task{

public:

	void run();
	void PasswordFound(std::string);
	CompareTask(char, ThreadArgs& const);
	CompareTask(std::vector<char> const, ThreadArgs& const, int const);

private:

	char digit_one; // TODO Turn into vector?
	int plen; // Length of the password combinations we are trying
	std::vector<char> const_digits;// The digits we are not changing in the combination
	ThreadArgs args; // TODO rename
};