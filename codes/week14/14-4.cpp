#include <iostream>
#include <stdlib.h>
using std::cout;
using std::ios;

int main(){
    system("clear"); // clear the console
    cout << "디폴트\n";
    cout << 100 << " : " << -50 << "\n\n";
    
    /*
    to set new format settings, previous setting values need to be removed
    */
    cout.unsetf(ios::dec);  
    cout.setf(ios::hex | ios::showbase | ios::uppercase);
    cout << "ios::hex | ios::showbase | ios::uppercase\n";
    cout << 100 << "\n\n";

    cout.unsetf(ios::hex | ios::showbase | ios::uppercase); // clear previous settings
    cout.setf(ios::scientific | ios::uppercase); // set new format settings
    cout << "scientific | ios::uppercase\n";
    cout <<  0.5 << " : " << 100.123 << "\n\n";

    /*
    if previous settings are removed, then default setting is applied
    */
    cout.unsetf(ios::scientific | ios::uppercase);
    cout << "디폴트\n";
    cout << 100 << " : " << -50 << '\n';
    return 0;
}