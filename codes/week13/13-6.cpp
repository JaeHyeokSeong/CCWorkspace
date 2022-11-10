#include <iostream>
using std::cout;
void ss(double a, double b, double* sum, double* sub){
    *sum = a + b;
    *sub = a - b;
}
int main(){
    double sum = 0, sub = 0;
    ss(10.2,5,&sum,&sub);
    cout << "sum: " << sum << ", sub: " << sub << '\n';
    return 0;
}