#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include <iostream>
#include "shape.hpp"

class Triangle : public Shape{
    public:
        Triangle(double width = 0, double height = 0) : Shape(width, height){

        }   
        double area(){
            return (width * height) / 2;
        } 
};
#endif // TRIANGLE_HPP