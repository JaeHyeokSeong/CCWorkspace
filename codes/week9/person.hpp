#include <iostream>

template <class T>
class Person{
    private:
        T height;
    public:
        void setHeight(T height){
            this->height = height;
        }
        T getHeight() const{
            return height;
        }
};