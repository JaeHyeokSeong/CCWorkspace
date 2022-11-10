#ifndef A_HPP
#define A_HPP
#include <iostream>

class A{
    private:
        int x;
    public:
        void setX(const int x){
            this->x = x;
        }
        friend int test(A& a);
};
#endif // A_HPP