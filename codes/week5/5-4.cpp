#include <iostream>
#include <string>
using namespace std;

string vending(int i);

int main(){
    string item = vending(1);
    cout << item << '\n';
    return 0;
}
string vending(int i){
    if(i==1){
        return "커피";
    } else{
        return "유자차";
    }
}