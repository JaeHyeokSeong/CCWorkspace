#include <iostream>
using std::cout;

int total_length(int x, int y){
	x -= 1;
	return x + y;
}
int main(){
	int x = 10, y = 10, result;
	result = total_length(x, y);
	cout << result << '\n'; // 19
	cout << x + y << '\n'; // 20
	return 0;
}
