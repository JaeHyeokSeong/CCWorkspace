#include <iostream>
using std::cout;

void updateArray(int array[], int length);
void printArray(int* array, int length);
int main(){
    int numbers[3] = {1,2,3};
    updateArray(numbers, 3);
    printArray(numbers, 3);
    return 0;
}
void updateArray(int array[], int length){
    for(int i = 0; i < length; i++) {
        array[i] = 10;
    }
}
void printArray(int* array, int length){
    for(int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << '\n';
}