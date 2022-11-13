#include <iostream>
using std::cout;
/*
2022 11월 13일 일요일
알고리즘 : 병합 정렬 (merge sort)
목표 : 7 6 5 8 3 5 9 1 10수들을 오름차순으로 정렬하세요
*/

#define MAX 9
int sorted_array[MAX];

/*
merge 함수는 이미 정렬되어진 배열들을
합치는 역할을 수행해준다.
*/
void merge(int* array, int start_index, int mid_index, int end_index){
    int i = start_index;
    int j = mid_index + 1;
    int k = start_index;

    // 작은 순서대로 sorted_array 배열에다가 삽입한다
    while(i <= mid_index && j <= end_index){
        if(array[i] > array[j]){
            sorted_array[k] = array[j];
            j++;
        } else {
            sorted_array[k] = array[i];
            i++;
        }
        k++;
    }

    // 남은 요소들을 sorted_array 에 대입해준다.
    // i 쪽 배열이 먼저 끝난 경우
    if(i > mid_index){
        while(j <= end_index){
            sorted_array[k++] = array[j++];
        }
    } 
    // j 쪽 배열이 먼저 끝난 경우
    if(j > end_index){
        while(i <= mid_index){
            sorted_array[k++] = array[i++];
        }
    }

    // 원래 배열에다가 정렬되어진 배열의 값을 대입
    for(int i = start_index; i <= end_index; i++){
        array[i] = sorted_array[i];
    }
}
/*
mergeSort() 함수에서는 배열을 반으로 나누는
작업을 수행해주는 함수이다.
*/
void mergeSort(int* array, int start_index, int end_index){
    if(start_index < end_index){
        int mid_index = (start_index + end_index) / 2;
        mergeSort(array, start_index, mid_index);
        mergeSort(array, mid_index + 1, end_index);
        merge(array, start_index, mid_index, end_index);
    }
}
void print(int* array){
    for(int i = 0; i < MAX; i++){
        cout << array[i] << ' ';
    }
    cout << '\n';
}
int main(){
    // [1] initialise
    int array[MAX] = {7, 6, 5, 8, 3, 5, 9, 1, 10};
    // [2] process
    mergeSort(array, 0, MAX - 1);
    // [3] output
    print(sorted_array);
    return 0;
}