/*
selection sort
time complexity : O(n^2)
*/
#include <iostream>
#define MAX 10

void selection_sort(int* array){
    for(int i = 0; i < MAX; i++){
        int min_index = i;
        for(int j = i + 1; j < MAX; j++){
            if(array[min_index] > array[j])
                min_index = j;
        }
        int tmp = array[i];
        array[i] = array[min_index];
        array[min_index] = tmp;
    }
}
int main(){
    // [1] input
    int array[MAX] = {3, 1, 5, 4, 2, 9, 0, 6, 8, 7};    
    // [2] process
    selection_sort(array);
    // [3] output
    for(int i = 0; i < MAX; i++){
        std::cout << array[i] << ' ';
    }
    return 0;
}