#include <iostream>
using std::cout;

int add(int a, int b);
double add(double a, double b);
int main(){
    cout << add(1, 2) << '\n';
    cout << add(1.0, 0.5) << '\n';
    return 0;
}
int add(int a, int b){
    return a+b;
}
double add(double a, double b){
    return a+b;
}