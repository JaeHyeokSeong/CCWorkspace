#include <iostream>

class Calculator{
    public:
        double add(double a = 0.0, double b = 0.0){
            return a+b;
        }      
        double subtract(double a = 0.0, double b = 0.0){
            return a - b;
        }
};