#include <iostream>
#include <stdlib.h>
#include "./header_files/bankAccount_file/bankAccount.hpp"
using std::cout;
using std::endl;

int main(){
    system("clear");
    User user("Jae Hyeok Seong", "seong5763@gmail.com");
    BankAccount account(&user);
    account.view_accountInfo();
    cout << endl;
    account.deposit(1000);
    cout << endl;
    account.withdraw(10001);
    cout << endl;
    account.withdraw(100);
    cout << endl;
    account.view_accountInfo();
    return 0;
}