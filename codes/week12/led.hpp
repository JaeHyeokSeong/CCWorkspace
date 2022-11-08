#ifndef LED_HPP
#define LED_HPP
#include <iostream>
using std::cout;
class Led{
    private:
        static int clicked;
    public:
        void turnOn(){
            cout << "turn on\n";
            clicked++;
        }
        void turnOff(){
            cout << "turn off\n";
            clicked++;
        }
        static int getClicked(){
            return clicked;
        }
};
int Led::clicked = 0;
#endif