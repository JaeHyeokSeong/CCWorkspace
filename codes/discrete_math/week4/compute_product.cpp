#include <iostream>

// pre-condition
// m is a nonnegative integer
// x is a real number
double product(int m, double x){
	int i = 0;
	double p = 0.0;
	while(i != m){
		p += x;
		i++;
	}
	return p;
}
int main(){
	double result = product(3, 2.1);
	std::cout << result << '\n';
	return 0;
}
