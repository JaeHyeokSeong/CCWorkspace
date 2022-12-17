/*
Program 2 - overfill an array
*/
#include <iostream>

int main(){
	int a[20];
	for(int i = 0; i < 30; i++){
		a[i] = i; // overfill an array will cause an overflow
	}
	return 0;
}
