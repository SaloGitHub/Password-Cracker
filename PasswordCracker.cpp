#include "Farm.h"
#include "Structs.h"
#include "Compare.h"
#include <iostream>
#include <vector>
using std::cout;
using std::string;

int const minl = 6;
int const maxl = 20;
int const total_c = 95;
string const password =  "j5g";

std::vector<char> character; // todo put somewhere else ACTUALLY DELETE

ThreadArgs arg;

/// Prototypes
void InitializeCharacters();
void compareStrings(); // TODO Rename MAKE SURE IT DOESNT HAVE THE SAME NAME AS A CLASS
void OneDigit();
void ThreeDigits();
void SixDigits();
bool PasswordFound(string);

void InitArgs();
void TwoDigits_Farm();
void ThreeDigits_Farm();
void FourDigits_Farm();

// Make a three digit cracker and then refactor all functions used

int main()
{
	InitArgs();
	//TwoDigits_Farm();
	ThreeDigits_Farm();

	/*
	while(!arg.found) {
		Crack(digitsint);
	}
	*/
}

void InitArgs() {
	arg.InitCharacters();
	arg.SetPassword(password);
}

void TwoDigits_Farm() {

	Farm farm;

	std::vector<char> fixed;
	int length = password.length();
	fixed.resize(length - 1);

	for (int i = 0; i < total_c; ++i) {
		fixed.at(0) = arg.character.at(i);
		farm.add_task(new CompareTask(fixed, arg, 2));
	}

	farm.run();
}

void ThreeDigits_Farm() {

	Farm farm;

	std::vector<char> fixed;
	int length = password.length();
	fixed.resize(length-1);

	for (int i = 0; i < total_c; ++i) {
		for (int j = 0; j < total_c; ++j) {
			fixed.at(0) = arg.character.at(i);
			fixed.at(1) = arg.character.at(j);
			farm.add_task(new CompareTask(fixed, arg, length));
		}
	}

	farm.run();
}

// TODO Refactor uper part

void FourDigits_Farm() {

	Farm farm;

	std::vector<char> fixed;
	int length = password.length();
	fixed.resize(length - 1);

	for (int i = 0; i < total_c; ++i) {
		for (int j = 0; j < total_c; ++j) {
			fixed.at(0) = arg.character.at(i);
			fixed.at(1) = arg.character.at(j);
			farm.add_task(new CompareTask(fixed, arg, length));
		}
	}

	farm.run();

	// Divide threads into combinations of the first half and then digits?

}

void InitializeCharacters() {

	int const DEC_START = 32;
	int const DEC_END = 127;
	
	for (int i = DEC_START; i < DEC_END; i++) {
		character.push_back(i);
	}

	// TODO Check if vectors are the faster implementation
}

void compareStrings() {

	cout << "Running..." << std::endl;


	// Options
	// A Write a function for each quantity of loops
	// B Somehow write a scalable function
	// C Do option A, make it thread, THEN figure out how to make it work with B

	// TODO Find the most efficient way to assing bf

	/*
	for (int i = 0; i < total_c; i++) {
		for (int j = 0; j < total_c; j++) {
			cout << c.at(i) << c.at(j) << std::endl;
		}
	}
	*/
}

void OneDigit() {

	string bf; // Brute Force: The current character combination we are trying

	for (int i = 0; i < total_c; i++) {
		bf = character.at(i);
		if (PasswordFound(bf)) break;
	}
}

void ThreeDigits() {

	string bf;

	for (int i = 0; i < total_c; i++) {
		for (int j = 0; j < total_c; j++) {
			for (int k = 0; k < total_c; k++) {

				bf.push_back(character.at(i));
				bf.push_back(character.at(j));
				bf.push_back(character.at(k));

				if (PasswordFound(bf)) break;

				bf.clear();
			}
		}
	}
}

void SixDigits() {

	string bf; // Brute Force: The current character combination we are trying

	for (int i = 0; i < total_c; i++) {
		for (int j = 0; j < total_c; j++) {
			for (int k = 0; k < total_c; k++) {
				for (int a = 0; a < total_c; a++) {
					for (int b = 0; b < total_c; b++) {
						for (int c = 0; c < total_c; c++) {

							bf.push_back(character.at(i));
							bf.push_back(character.at(j));
							bf.push_back(character.at(k));
							bf.push_back(character.at(a));
							bf.push_back(character.at(b));
							bf.push_back(character.at(c));

							if (PasswordFound(bf)) { break; }

							bf.clear();
						}
					}
				}
			}
		}
	}

	// How to make a recursive loop
}


bool PasswordFound(string str) {
	if (str == password) {
		cout << "PASSWORD FOUND" << std::endl;
		cout << str << std::endl;
		return true;
	} return false;
}