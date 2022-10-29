#include <iostream>
using std::cout;

double multiply(double n1, double n2, double n3 = 1, double n4 = 1, double n5 = 1);
int main(){
    cout << "result: " << multiply(1,2) << '\n';
    cout << "result: " << multiply(1,2,10) << '\n';
    return 0;
}
double multiply(double n1, double n2, double n3, double n4, double n5){
    return n1*n2*n3*n4*n5;
}