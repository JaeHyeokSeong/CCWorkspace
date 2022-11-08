#include <iostream>

class A2{
    private:
        int a2;
    public:
        A2(const int a2){
            this->a2 = a2;
        }
        ~A2(){
            std::cout << "A2 클래스의 객체가 소멸 되었습니다.\n";
        }
        int getA2() const{
            return a2;
        }
};