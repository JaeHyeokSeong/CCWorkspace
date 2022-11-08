#include <iostream>
#include "airplane.hpp"
#include "balloon.hpp"
using std::cout;

int main(){
    Airship* airships[2];
    Airplane a330(300, 30000, 'j', 14000);
    Ballon b1(10,300,'h',600);
    airships[0] = &a330;
    airships[1] = &b1;

    for(int i = 0; i < 2; i++){
        airships[i]->show();
    }
    return 0;
}