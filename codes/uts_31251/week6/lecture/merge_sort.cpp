/*
merge sort
time complexity : O(n*logn)
*/

#include <iostream>
#define MAX 10

int sorted_array[MAX];

void ascending_merge(int* array, int start_index, int mid_index, int end_index){
    int i = start_index, j = mid_index + 1, k = start_index;
    while(i <= mid_index && j <= end_index){
        if(array[i] < array[j]){
            sorted_array[k++] = array[i++];
        } else{
            sorted_array[k++] = array[j++];
        }
    }
    // i index 부분이 먼저 다 이용되어진 경우 나머지 j index를 순서대로 대입해준다
    if(i > mid_index){
        while(j <= end_index){
            sorted_array[k++] = array[j++];
        }
    }
    // j index 부분이 먼저 다 이용되어진 경우 나머지 i index를 순서대로 대입해준다
    if(j > end_index){
        while(i <= mid_index){
            sorted_array[k++] = array[i++];
        }
    }
    // 정렬되어진 숫자들을 다시 원래 배열에다가 대입 시켜주기
    for(i = start_index; i <= end_index; i++){
        array[i] = sorted_array[i];
    }
}

// ascending order
void ascending_merge_sort(int* array, int start_index, int end_index){
    if(start_index < end_index){
        int mid_index = (start_index + end_index) / 2;
        ascending_merge_sort(array, start_index, mid_index);
        ascending_merge_sort(array, mid_index + 1, end_index);
        ascending_merge(array, start_index, mid_index, end_index);
    }
}
void descending_merge(int* array, int start_index, int mid_index, int end_index){
    int i = start_index, j = mid_index + 1, k = start_index;
    while(i <= mid_index && j <= end_index){
        if(array[i] < array[j]){
            sorted_array[k++] = array[j++];
        } else{
            sorted_array[k++] = array[i++];
        }
    }
    if(i > mid_index){
        while(j <= end_index){
            sorted_array[k++] = array[j++];
        }
    }
    if(j > end_index){
        while(i <= mid_index){
            sorted_array[k++] = array[i++];
        }
    }
    for(int i = start_index; i <= end_index; i++){
        array[i] = sorted_array[i];
    }
}
void descending_merge_sort(int* array, int start_index, int end_index){
    if(start_index < end_index){
        int mid_index = (start_index + end_index) / 2;
        descending_merge_sort(array, start_index, mid_index);
        descending_merge_sort(array, mid_index + 1, end_index);
        descending_merge(array, start_index, mid_index, end_index);
    }
}
int main(){
    // [1] input
    int array[MAX] = {3, 1, 5, 4, 2, 9, 0, 6, 8, 7};
    // [2] process
    ascending_merge_sort(array, 0, MAX - 1);
    // [3] output
    for(int i = 0; i < MAX; i++){
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';
    // [4] process
    descending_merge_sort(array, 0, MAX - 1);
    // [5] output
    for(int i = 0; i < MAX; i++){
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';
}