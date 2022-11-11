#include <iostream>
using std::cout;

void divide(double a, double b){
    try{
        if(!b){
            throw b;
        }
        cout << a/b << '\n';
    }
    catch(double){
        cout << "error: cannot divide by zero\n";
    }
}
int main(){
    divide(10,0);
    return 0;
}