#ifndef AIRSHIP_HPP
#define AIRSHIP_HPP
#include <iostream>
using std::cout;

class Airship{
    protected:
        int passenger;
        double cargo;
    public:
        virtual void show(){
            cout << "passenger: " << passenger << "\ncargo: " << cargo << '\n';
        }
};
#endif // AIRSHIP_HPP