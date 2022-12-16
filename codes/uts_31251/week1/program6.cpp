/*
Program 6 - pointer
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
		void print_volumn(){
			std::cout << length * breadth * height << '\n';
		}
};

int main(){
	// 동적 할당
	Box* p_box = new Box(1, 2, 3);
	p_box->print_volumn(); // 6
	// 동적 할당한 메모리 삭제해주기
	delete p_box;
	return 0;
}
