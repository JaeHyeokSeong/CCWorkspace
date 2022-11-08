#include <iostream>

class Fruit{
    public:
        int apple;
        int banana;
        Fruit(int apple, int banana){
            this->apple = apple;
            this->banana = banana;
        }
};
int main(){
    Fruit f1(5,10);
    Fruit f2 = f1;
    std::cout << f2.apple << '\n';
    return 0;
}