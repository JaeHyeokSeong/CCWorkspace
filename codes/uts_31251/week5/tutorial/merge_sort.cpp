/*
merge sort
time complexity : O(n*logn)
*/
#include <iostream>
#define MAX 10

int sorted_array[MAX];

void merge(int array[], int start_index, int mid_index, int end_index){
    int i = start_index;
    int j = mid_index + 1;
    int k = start_index;

    // 오름차순 기준
    while(i <= mid_index && j <= end_index){
        if(array[i] < array[j])
            sorted_array[k++] = array[i++];
        else    
            sorted_array[k++] = array[j++];
    }

    // 내림차순 기준
    // while(i <= mid_index && j <= end_index){
    //     if(array[i] < array[j])
    //         sorted_array[k++] = array[j++];
    //     else    
    //         sorted_array[k++] = array[i++];
    // } 

    if(i > mid_index){
        while(j <= end_index)
            sorted_array[k++] = array[j++];
    } 

    if(j > end_index){
        while(i <= mid_index)
            sorted_array[k++] = array[i++];
    }

    for(i = start_index; i <= end_index; i++){
        array[i] = sorted_array[i];
    }
}
void merge_sort(int array[], int start_index, int end_index){
    if(start_index < end_index){
        int mid_index = (start_index + end_index) / 2;
        merge_sort(array, start_index, mid_index);
        merge_sort(array, mid_index + 1, end_index);
        merge(array, start_index, mid_index, end_index);
    }
}

int main(){
    int array[MAX] = {3, 1, 2, 5, 10, 4, 6, 9, 8, 7};
    merge_sort(array, 0, MAX - 1);

    for(int i = 0; i < MAX; i++){
            std::cout << array[i] << ' ';
        }
        std::cout << '\n';
    return 0;
}