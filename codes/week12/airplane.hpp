#ifndef AIRPLANE_HPP
#define AIRPLANE_HPP
#include <iostream>
#include "airship.hpp"
class Airplane : public Airship{
    private:
        char engine;
        double range;
    public:
        Airplane(int passenger, double cargo, char engine, double range){
            this->passenger = passenger;
            this->cargo = cargo;
            this->engine = engine;
            this->range = range;
        }
        void show(){
            Airship::show();
            cout << "engine: " << ((engine == 'p') ? "프로펠러\n" : "제트\n");
            cout << "range: " << range << '\n';
        }
};
#endif