#pragma once
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
//Type writer function for Aesthetics
void typewriter(string text, int speed) {
	int x = 0;
	while (text[x] != '\0')
	{
		cout << text[x];
		Sleep(speed);
		x++;
	};
	cout << endl;
}