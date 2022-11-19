#include <iostream>
using std::cout;

// 이미 계산한 결과를 기록하는 배열
int result[100] = {};
int fibonacci_number(int i){
	if(i==1)
		return 1;
	if(i==2)
		return 1;
	if(result[i] != 0)
		return result[i];
	return result[i] = fibonacci_number(i-1) + fibonacci_number(i-2);
}
int main(){
	cout << fibonacci_number(30) << '\n';
}
