/*
Program 9 - reference (참조자)
*/
#include <iostream>

int total_length(int& x, int& y){
	x -= 1;
	return x + y;
}
int main(){
	int x = 10, y = 10;
	int result = total_length(x, y);
	std::cout << result << '\n'; // 19
	std::cout << x + y << '\n'; // 19
	return 0;
}
