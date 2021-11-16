#pragma once
#include <iostream>
#include <string>
using namespace std;
//TUTORIAL
void tutorial() {
	char tutopt;
	cout << "GAMEPLAY INSTRUCTIONS: whilst playing press enter to progress through the game... try it now." << endl;
	cin.get();
	cout << "GAMEPLAY INSTRUCTIONS : you may be asked to choose an option, for example... " << endl;
	cout << "EXAMPLE: choose attack or upgrade: type 'a' OR 'u': \n";
	cin >> tutopt;
	cout << "great. thats pretty much it... happy dueling!!" << endl;
}