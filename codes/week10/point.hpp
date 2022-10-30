#include <iostream>

class Point{
    private:
        int x, y;
    public:
        Point(int x=0, int y=0){
            this->x = x;
            this->y = y;
        }
        int getX() const{
            return x;
        }
        int getY() const{
            return y;
        }
        void view() const{
            std::cout << '(' << x << ", " << y << ")\n";
        }
        // 후치 a++
        void operator ++(int){
            this->x += 1;
            this->y += 1;
        }
        // 전치 ++a
        void operator ++(){
            this->x += 1;
            this->y += 1;
        }
        Point operator +(Point& p){
            Point temp;
            temp.x = this->getX() + p.getX();
            temp.y = this->getY() + p.getY();
            return temp;
        }
        Point operator *(Point p){
            Point temp;
            temp.x = x * p.x;
            temp.y = y * p.y;
            return temp;
        }
        bool operator ==(Point p){
            if(x == p.x && y == p.y)
                return 1;
            return 0;
        }
        bool operator !=(Point p){
            if(x != p.x || y != p.y)
                return 1;
            return 0;
        }
        operator int(){
            return x*y; // 여기에서 코드 구현은 전적이 프로그래머의 재량입니다.
        }
};