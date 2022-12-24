/*
quick sort
time complexity : 
*/

#include <iostream>
#define MAX 10

void ascending_quick_sort(int* array, int start_index, int end_index){
    if(start_index >= end_index) return;
    // pivot 값 선정 기준
    // 가장 첫번째 index를 기준으로 pivot값을 선택하는 방법 적용
    int pivot = start_index, i = pivot + 1, j = end_index;
    // i 그리고 j 가 서로 엇갈리기 전까지 계속해서 반복
    while(i <= j){
        // i 기준에서는 pivot 값 보다 큰 값을 찾을때 까지 증가
        while(i <= end_index && array[pivot] >= array[i]){
            i++;
        }
        // j 기준에서는 pivot 값 보다 작은 값을 찾을때 까지 감소
        while(j > start_index && array[pivot] <= array[j]){
            j--;
        }
        // i 그리고 j 가 서로 엇갈린 경우 pivot 값이랑 j 값을 서로 swap
        if(i > j){
            int tmp = array[pivot];
            array[pivot] = array[j];
            array[j] = tmp;
        }
        // i 그리고 j 가 아직 서로 엇갈리지 않은 경우 i, j 값을 서로 swap 
        else{
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }
    // 재귀함수 호출
    ascending_quick_sort(array, start_index, j - 1);
    ascending_quick_sort(array, j + 1, end_index);
}
void descending_quick_sort(int* array, int start_index, int end_index){
    if(start_index >= end_index) return;
    int pivot = start_index, i = pivot + 1, j = end_index;
    // i, j 가 서로 엇갈리기 전까지는 계속 반복
    while(i <= j){
        // i 는 pivot 값 보다 작은 값을 찾는다
        while(i <= end_index && array[pivot] <= array[i]){
            i++;
        }
        // j 는 pivot 값 보다 큰 값을 찾는다
        while(j > start_index && array[pivot] >= array[j]){
            j--;
        }
        // i, j 가 서로 엇갈린 경우
        if(i > j){
            int tmp = array[pivot];
            array[pivot] = array[j];
            array[j] = tmp;
        }
        // i, j 가 서로 엇갈리지 않은 경우
        else{
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }
    
    descending_quick_sort(array, start_index, j - 1);
    descending_quick_sort(array, j + 1, end_index);
}
int main(){
    // [1] input
    int array[MAX] = {3, 1, 5, 4, 2, 9, 0, 6, 8, 7};
    // [2] process
    ascending_quick_sort(array, 0, MAX - 1);
    // [3] output
    for(int i = 0; i < MAX; i++){
        std::cout << array[i] << ' '; 
    }
    std::cout << '\n';
    // [4] process
    descending_quick_sort(array, 0, MAX - 1);
    // [5] output
    for(int i = 0; i < MAX; i++){
        std::cout << array[i] << ' '; 
    }
    std::cout << '\n';
    return 0;
}