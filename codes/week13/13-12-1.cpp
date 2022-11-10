#include <iostream>
#include <string>
using std::string;
using std::cout;
int main(){
    string str = "Jae";
    str.push_back('H');
    str.push_back('y');
    str.push_back('e');
    str.push_back('o');
    str.push_back('k');

    for(int i = 0; i < str.size(); i++){
        cout << str[i];
    }
    cout << '\n';

    // cout << str << '\n';
    return 0;
}