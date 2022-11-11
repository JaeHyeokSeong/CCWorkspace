#include <iostream>
#include <stdlib.h>
using std::cout;

int main(){
    system("clear");
    cout << "default\n";
    cout << -50 << '\n';
    cout << "width(10)\n";
    cout.width(10);
    cout << -50 << '\n';
    cout << "width(10) | fill(*)\n";
    cout.fill('*');
    cout.width(10);
    cout << -50 << '\n';
    cout.width(10);
    cout << 3.14 << '\n';

    cout.fill(' ');
    //cout.precision(6);
    cout << 3.14159265359 << '\n';

    cout << std::fixed;
    cout.precision(2);
    cout << 3.14159265359 << '\n';

    cout.copyfmt(std::ios(NULL));
    cout.precision(10);
    cout << "default\n";
    cout << 3.14159265359 << '\n';
    return 0;
}