#include <iostream>
#include "name.hpp"
using std::cout;

class Phone: public Name{
    private:
        string phone;
    public:
        Phone(){
            setName();
            setPhone();
        }
        void setPhone(const string phone = ""){
            this->phone = phone;
        }
        string getPhone() const{
            return phone;
        }
        void printPhone() const{
            if(getName() == "" && phone == ""){
                cout << "이름과 전화번호를 먼저 입력해 주세요\n";
                return;
            }
            cout << getName() << "의 전화번호는 " << phone << '\n';            
        }
};