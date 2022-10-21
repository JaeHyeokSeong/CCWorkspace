#include <iostream>
using namespace std;

class Person{
    private:
        string name, gender, address;
        int age;
    public:
        Person(string p_name, string p_gender, string p_address, int p_age);
        string info();
};