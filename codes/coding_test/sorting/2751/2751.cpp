#include <iostream>
#include <algorithm>
using std::cout;
using std::cin;
using std::sort;

int array[1000001];

void readInput(int length){
	for(int i = 0; i < length; i++){
		cin >> array[i];
	}
}
void print(int length){
	for(int i = 0; i < length; i++){
		cout << array[i] << '\n';
	}
}
int main(){
	// [1] initialise
	int length;
	// [2] input
	cin >> length;
	readInput(length);
	// [3] process
	sort(array, array + length);
	// [4] output
	print(length);
	return 0;
}
