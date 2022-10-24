#include <iostream>
using std::cout;
using std::cin;
using std::getline;
using std::string;
int main(){
    string names[2]; 
    cout << "Enter family name: ";
    cin >> names[0];
    cin.ignore(100, '\n'); // 첫번째에서 입력받은후에 엔터를 누르면 그값이 여기에서 잡하게 된다.
    cout << "Enter first name: ";
    getline(cin, names[1]);

    cout << "Your name is \"" << names[0] << ", " << names[1] << "\"\n"; 
    return 0;
}