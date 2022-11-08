#include <iostream>

class A1{
    private:    
        int a1;
    public:
        A1(const int a1){
            this->a1 = a1;
        }
        ~A1(){
            std::cout << "A1 클래스의 객체가 소멸 되었습니다.\n";
        }
        int getA1() const{
            return a1;
        }
};