#include <iostream>

// Auto type conversion
int sum(double x, double y){
    int z = -1;
    return x + y + z;
}
int main(){
    double a = 10, b = 20.5;
    std::cout << sum(a,b) << '\n'; // 29
    return 0;
}