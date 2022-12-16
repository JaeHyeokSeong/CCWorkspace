/*
Program 8 - pointer to simple data types
*/
#include <iostream>

int main(){
	double* ptr = nullptr;
	ptr = new double; // default value 0.0 으로 초기화 된다
	*ptr = 3;
	std::cout << *ptr + 1 << '\n';
	delete ptr;
	return 0;
}
