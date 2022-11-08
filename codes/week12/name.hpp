#include <iostream>
using std::string;

class Name{
    private:
        string name;
    public:
        void setName(const string name = "") {
            this->name = name;
        }
        string getName() const{
            return name;
        }
};