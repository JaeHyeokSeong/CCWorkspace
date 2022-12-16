/*
Program 5 - constructor
*/
#include <iostream>

class Box{
	private:
		double length, breadth, height;
	public:
		// default constructor
		Box(){
			length = 2.0; breadth = 2.0; height = 2.0;
		}
		// constructor
		Box(double length, double breadth, double height){
			this->length = length;
			this->breadth = breadth;
			this->height = height;
		}
		void setLength(const double length){
			this->length = length;
		}
		double getVolumn() const{
			return length * breadth * height;
		}
};
int main(){
	Box box;
	box.setLength(1.0);
	std::cout << box.getVolumn() << '\n'; // 4
	return 0;
}
