#ifndef USER_H
#define USER_H
#include <iostream>

class User{
    protected:
        std::string name;
        int age;        
    public:
        User(std::string name, int age);
        virtual ~User();
        virtual void login() = 0;
};

#endif // USER_H