#include <iostream>

int ack_func(int m, int n){
    if(m == 0) return n + 1;
    else if(n == 0) return ack_func(m - 1, 1);
    else return ack_func(m - 1, ack_func(m, n - 1));
}

int main(){
    std::cout << ack_func(1, 2) << '\n'; // 4
    return 0;
}
