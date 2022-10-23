#include <iostream>
using std::string;
using std::to_string;

class Person{
    private:
        string name;
        int age, weight;
    public:
        Person(string name, int age, int weight);
        string toString();
};