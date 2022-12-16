/*
Program 3 - public attributes
*/
#include <iostream>

class Box{
	public:
		double length, breadth, height;

		double calculate_volumn(){
			return length * breadth * height;
		}
};
int main(){
	// Declare a class object
	Box box1;
	box1.height = 1.0;
	box1.length = 2.0;
	box1.breadth = 3.0;

	double volumn = box1.calculate_volumn();
	std::cout << volumn << '\n'; // 6
	return 0;
}
