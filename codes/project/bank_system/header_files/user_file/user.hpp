#ifndef USER_HPP
#define USER_HPP
#include <iostream>
using std::string;
class User{
    private:
        string name, email_address;
    public:
        User(string name, string email_address){
            this->name = name;
            this->email_address = email_address;
        }
        string getName() const{
            return name;
        }
        void setName(const char* name){
            this->name = name;
        }
        string getEmailAddress() const{
            return email_address;
        }
        void setEmailAddress(const char* email_address){
            this->email_address = email_address;
        }
};
#endif // USER_HPP