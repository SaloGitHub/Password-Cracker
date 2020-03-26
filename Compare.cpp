#include "Compare.h"
#include <complex>

CompareTask::CompareTask(char char_val, ThreadArgs& const thread_args) {
	digit_one = char_val;
	args = thread_args;
}

CompareTask::CompareTask(std::vector<char> const fixed_digits , ThreadArgs& const thread_args, int const len) {
	const_digits = fixed_digits;
	args = thread_args;
	plen = len;
}

void CompareTask::run() {

	if (args.found) {
		return;
	}

	// TODO Just make it stop threads once it finds it

	std::string combination;

	for (int i = 0; i < 95; i++) {

		//combination.push_back(const_digits.at(0));

		for (int j = 0; j < const_digits.size(); j++) {
			combination.push_back(const_digits.at(j));
		}

		combination.push_back(args.character.at(i));

		if (combination == args.password) {
			args.found = true;
			PasswordFound(combination);
			return;
		}

		combination.clear();
	}
}

/*void CompareTask::run() {

	if (args.found) {
		return;
	}

	// TODO Just make it stop threads once it finds it

	std::string combination;

	for (int i = 0; i < 95; i++) {

		combination.push_back(digit_one);
		combination.push_back(args.character.at(i));

		if (combination == args.password) {
			args.found = true;
			PasswordFound(combination);
			return;
		}

		combination.clear();
	}
}*/

void CompareTask::PasswordFound(std::string cracked_password) {

	std::cout << "\033[2J\033[1;1H"; // Clears the screen
	std::cout << "Password is " << cracked_password;
}

// TODO Add something if password is not found and make it go on to next thread