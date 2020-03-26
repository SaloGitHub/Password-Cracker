#pragma once
#include <iostream>
#include <vector>

struct ThreadArgs {

	std::string password;
	std::vector<char> character;
	bool found = false;

	void InitCharacters() {
		for (int i = 32; i < 127; i++) {
			character.push_back(i);
		}
	}

	void SetPassword(std::string str) {
		password = str;
	}

};