#include <iostream>
using std::cout;
int* test(int a){
    int* pA = new int[a];
    return pA;
}
int main(){
    int a = 10;
    
    int* t = test(a);
    for(int i = 0; i < a; i++) {
        cout << t[i] << '\n';
    }

    return 0;
}