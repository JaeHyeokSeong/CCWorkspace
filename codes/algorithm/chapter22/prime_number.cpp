/*
소수는 1과 자기자신의 수로 이루어진 수를 의미한다
*/
#include <iostream>
#include <math.h>
bool isPrimeNumber(int x){
	int end = (int)sqrt(x);
	for(int i = 2; i <= end; i++){
		if(x % i == 0)
			return false; // 소수가 아님
	}
	return true; // 소수임
}
int main(){
	printf("%d\n", isPrimeNumber(17));
	return 0;
}
