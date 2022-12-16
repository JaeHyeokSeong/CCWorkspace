/*
Program 4 - private attributes
*/
#include <iostream>

class Box{
	private:
		double length, breadth, height;
	public:
		Box(double length = 0.0, double breadth = 0.0, double height = 0.0){
			this->length = length;
			this->breadth = breadth;
			this->height = height;
		}
		double get_volumn(){
			return length * breadth * height;
		}
};

int main(){
	Box box1(1.0, 2.0, 3.0);
	double volumn = box1.get_volumn();
	std::cout << volumn << '\n'; // 6
	return 0;
}
