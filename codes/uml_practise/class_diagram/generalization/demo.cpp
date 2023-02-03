/*
UML 
    - class diagram
    - (generalization)
*/
#include "Customer.h"
#include <vector>

int main(){
    Customer* cus1 = new Customer("J_H_S", 23);
    Customer* cus2 = new Customer("J_W_S", 28);

    std::vector<User*> users;
    users.push_back(cus1);
    users.push_back(cus2);

    for(int i = 0; i < users.size(); i++){
        users[i]->login();
    }

    for(int i = 0; i < users.size(); i++){
        delete users[i];
    }
}