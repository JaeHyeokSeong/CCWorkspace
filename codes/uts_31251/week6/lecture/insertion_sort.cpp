/*
insertion sort
time complexity : O(n^2)
*/
#include <iostream>
#define MAX 10

void ascending_order_insertion_sort(int* array, int size){
    for(int i = 0; i < size - 1; i++){
        int j = i;
        while(j >= 0 && array[j] > array[j+1]){
            int tmp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = tmp;
            j--; 
        }
    }
}
void descending_order_insertion_sort(int* array, int size){
    for(int i = 0; i < size - 1; i++){
        int j = i;
        while(j >= 0 && array[j] < array[j + 1]){
            int tmp = array[j + 1];
            array[j + 1] = array[j];
            array[j] = tmp;
            j--;
        }
    }
}
int main(){
    // [1] input
    int array[MAX] = {3, 1, 5, 4, 2, 9, 0, 6, 8, 7};
    // [2] process 1
    ascending_order_insertion_sort(array, MAX);
    // [3] output 1
    std::cout << "ascending order: ";
    for(int i = 0; i < MAX; i++){
        std::cout << array[i] << ' ';
    }
    // [4] process 2
    descending_order_insertion_sort(array, MAX);
    // [5] output 2
    std::cout << "\ndescending order: ";
    for(int i = 0; i < MAX; i++){
        std::cout << array[i] << ' ';
    }
    return 0;
}