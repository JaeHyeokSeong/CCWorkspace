#include <iostream>
using std::cout;
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int a = 10;
    int b = 100;
    cout << "before\n";
    cout << "a: " << a << ", b: " << b << '\n';
    swap(&a, &b);
    cout << "after\n";
    cout << "a: " << a << ", b: " << b << '\n';
    return 0;
}