#include <iostream>

using namespace std;

//pointer array to store wins nd loses.

int wins[2]{ 0,0 }, loses[2]{ 0,0 };
int* p1Rec[2]{ &wins[0],&loses[0] }, * cpuRec[2]{ &wins[1],&loses[1] };

void ref(int& value) {
	value++;
}
	
