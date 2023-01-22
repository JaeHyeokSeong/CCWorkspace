#include <iostream>
#define MAX 1001

int counting(int* numbers, int size,  int n){
	int cnt = 0;
	for(int i = 1; i < size; i++){
		if(numbers[i] % n == 0) cnt++;
	}
	return cnt;
}

int main(){
	int numbers[MAX], n = 1;
	for(int i = 1; i < MAX; i++){
		numbers[i] = n++;
	}

	int result = counting(numbers, MAX, 15);
	std::cout << result << '\n';
	return 0;
}
