#include <iostream>

int counting(int* numbers, int size,  int n){
	int cnt = 0;
	for(int i = 0; i < size; i++){
		if(numbers[i] % n == 0) cnt++;
	}
	return cnt;
}

int main(){
	int numbers[900], n = 100;
	for(int i = 0; i < 900; i++){
		numbers[i] = n++;
	}
	int result = counting(numbers, 900, 5);
	std::cout << result << '\n';
	return 0;
}
