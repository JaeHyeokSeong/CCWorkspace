#include <iostream>
using std::cout;
int main(){
    int y = 10;
    int &x = y;
    y++;
    cout << x << '\n';
    return 0;
}