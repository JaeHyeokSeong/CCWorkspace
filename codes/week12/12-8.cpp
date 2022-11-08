#include <iostream>
#include "led.hpp"
using std::cout;

int main(){
    Led led1;
    led1.turnOn();
    led1.turnOff();
    Led led2;
    led2.turnOn();
    cout << "total clicked: " << Led::getClicked() << '\n';
}