#include <iostream>
using std::cout;

int main(){
    char s1[100] = "hello world";
    char cpy_s1[100];
    strcpy(cpy_s1, s1);
    cout << cpy_s1 << '\n';
    return 0;
}