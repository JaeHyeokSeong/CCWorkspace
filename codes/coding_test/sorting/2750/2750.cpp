#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int array[1001];

void read_input(int length){
    for(int i = 0; i < length; i++){
        cin >> array[i];
    }
}
void print(int length){
    for(int i = 0; i < length; i++){
        cout << array[i] << endl;   
    }
}
void selection_sort(int length){
    int min, temp;
    for(int i = 0; i < length; i++){
        min = array[i];
        for(int j = i; j < length-1; j++){
            if(min > array[j+1]){
                temp = min;
                min = array[j+1];
                array[j+1] = temp;
            }
        }
        array[i] = min;
    }
}
int main(){
    // [1] initialise
    int length;
    // [2] input
    cin >> length;
    read_input(length);
    // [3] process
    selection_sort(length);
    // [4] output
    print(length);
    return 0;
}