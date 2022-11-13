#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP
#include <iostream>
#include "../user_file/user.hpp"
using std::cout;
using std::endl;

class BankAccount{
    private:
        User* user;
        double balance;
    public:
        BankAccount(User* user){
            this->user = user;
            balance = 0.0;
        }
        void withdraw(double amount){
            cout << "================= 인출 정보 =================" << endl << endl;
            if(amount > balance){
                cout << "잔액 부족" << endl;
            } else{
                balance -= amount;
                cout << '$' << amount << "원이 인출 되었습니다." << endl;
                cout << "남은잔액 : $" << balance << "원" << endl;
            }
            cout << endl << "=============================================" << endl << endl;
        }
        void deposit(double amount){
            balance += amount;
            cout << "================= 입금 정보 =================" << endl << endl;
            cout << '$' << amount << "원이 입금 되었습니다." << endl;
            cout << "현재잔액 : $" << balance << "원" << endl;
            cout << endl << "=============================================" << endl << endl;
        }
        void view_accountInfo(){
            cout << "================= 고객 정보 =================" << endl << endl;
            cout << "이름 : " << user->getName() << endl;
            cout << "이메일 주소 : " << user->getEmailAddress() << endl;
            cout << "현재잔액 :  $" << balance << "원" << endl;
            cout << endl << "=============================================" << endl << endl;
        }
};
#endif // BANKACCOUNT_HPP