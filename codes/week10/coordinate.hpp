#include <iostream>

class Coordinate{
    private:
        int x, y;
    public:
        Coordinate(int x=0, int y=0){
            this->x = x;
            this->y = y;
        }
        int getX() const{
            return x;
        }
        int getY() const{
            return y;
        }
        Coordinate operator -(const Coordinate& c){
            Coordinate temp;
            temp.x = x - c.x;
            temp.y = y - c.y;
            return temp;
        }
        void view() const{
            std::cout << '(' << x << ", " << y << ")\n";
        }
};