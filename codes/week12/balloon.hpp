#ifndef BALLON_HPP
#define BALLON_HPP
#include <iostream>
#include "airship.hpp"

class Ballon: public Airship{
    private:
        char g;
        double altitude;
    public:
        Ballon(int passenger, double cargo, char g, double altitude){
            this->passenger = passenger;
            this->cargo = cargo;
            this->g = g;
            this->altitude = altitude;
        }
        void show() {
            Airship::show();
            cout << "gas: " << (g == 'h' ? "헬륨\n" : "수소\n");
            cout << "altitude: " << altitude << '\n';
        }
};
#endif // BALLON_HPP   