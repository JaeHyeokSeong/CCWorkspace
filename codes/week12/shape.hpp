#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <iostream>

class Shape{
    protected:
        double width, height;
    public:
        Shape(double width, double height){
            this->width = width;
            this->height = height;
        }
        virtual double area() = 0;
};
#endif // SHAPE_HPP