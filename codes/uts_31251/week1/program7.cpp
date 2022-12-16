/*
Program 7 - dereferencing a pointer
*/
#include <iostream>

class Box{
	private:
		double length, breadth, height;
	public:
		Box(double length, double breadth, double height){
			this->length = length;
			this->breadth = breadth;
			this->height = height;
		}
		double print_volumn() const{
			return length * breadth * height;
		}
};
int main(){
	Box* p_box = new Box(1, 2, 3);
	std::cout << (*p_box).print_volumn() << '\n'; // 6
	delete p_box;
	return 0;
}
