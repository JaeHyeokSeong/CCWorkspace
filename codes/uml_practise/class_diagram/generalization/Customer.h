#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "User.h"

class Customer : public User{
    public:
        Customer(std::string name, int age);
        ~Customer();
        virtual void login();
};

#endif // CUSTOMER_H