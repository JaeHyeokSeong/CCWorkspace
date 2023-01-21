#include <iostream>

int factorial(int n){
    if(n == 0) return 1;
    return n * factorial(n - 1);
}

int n_permutation(int n, int r){
    int a = 1;
    for(int i = 0; i < r; i++){
        a *= n--;
    }
    return a;
}

int main(){
    int a = factorial(3);
    std::cout << "result: " << a << '\n';

    a = n_permutation(5, 5);
    std::cout << "result: " << a << '\n';
    return 0;
}