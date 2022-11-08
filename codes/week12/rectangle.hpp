#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <iostream>
#include "shape.hpp"
class Rectangle : public Shape{
    public:
        Rectangle(double width = 0, double height = 0) : Shape(width, height){

        }
        double area(){
            return width * height;
        }
};
#endif // RECTANGE_HPP