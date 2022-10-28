#include <iostream>
using std::cout;
using std::cin;

int main(){
    int size = 0;
    cout << "Enter array size: ";
    cin >> size;

    int* pNumbers = new int[size];
    if(pNumbers == nullptr){
        cout << "[Warning] Insufficient memory in the heap\n";
        return 1;
    }
    for(int i = 0; i < size; i++) {
        cout << "Enter a number: ";
        cin >> pNumbers[i];
    }

    cout << "You have entered following numbers\n=> ";
    for(int i = 0; i < size; i++) {
        cout << pNumbers[i] << " ";
    }
    cout << '\n';

    delete []pNumbers;
    return 0;
}