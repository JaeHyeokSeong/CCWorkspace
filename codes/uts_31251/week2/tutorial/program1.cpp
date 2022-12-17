/*
Program 1 - add things to container
*/
#include <iostream>
#include <vector>

int main(){
	int a[20];
	std::vector<int> v;
	for(int i = 0; i < 20; i++){
		a[i] = i;
		v.push_back(i);
	}
	return 0;
}
