#include <iostream>
using std::cout;

int main(){
    char name[] = "Jae";
    *name = 'j';
    char a = *name;
    cout << name[0] << a;
    return 0;
}