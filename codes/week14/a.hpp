#ifndef A_HPP
#define A_HPP
#include <iostream>
class A{
    private:
        int a;
    public:
        A(int a){
            this->a = a;
        }
        int getA() const{
            return a;
        }
};
#endif // A_HPP