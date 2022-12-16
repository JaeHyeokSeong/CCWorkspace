/*
program 2 - variable scope, type conversion
*/
#include <iostream>

// Global variable declaration
int g;

int main(){
	// Local variable declaration
	int a, b, c = -1;
	
	// Initialization of variables
	a = 10; b = 20;
	g = a + b + c;

	std::cout << g << '\n';
	return 0;
}
