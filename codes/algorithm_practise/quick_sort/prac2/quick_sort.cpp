#include <iostream>
#include "quick_sort.hpp"

void my_algorithm::quick_sort(int* array, int start, int end){
    // 재귀 함수 종결문
    if(start >= end) return;
    // pivot, i, j, tmp 변수 초기화 합니다.
    // pivot 값은 배열의 시작 인덱스로 합니다.
    // i 는 pivot 값의 그 다음 값의 인덱스로 합니다.
    // j 는 배열의 가장 마지막 인덱스 값을 가지도록 합니다.
    // tmp 는 어떠한 두 값을 교환할때 사용되어지는 임시 변수 입니다.
    int pivot = start,  i = pivot + 1, j = end, tmp = 0;

    // quick sort에서는 i 그리고 j 값이 서로 엇갈리기 전까지 계속 진행해줘야 합니다.
    // [1] i 그리고 j 값이 서로 엇갈린 경우 배열에서 j값 인덱스에 위치한 값이랑 pivot 인덱스 값에 
    // 위치한 값을 서로 바꾸어 줍니다.
    // [2] i 그리고 j 값이 아직 서로 엇갈리지 않은 경우 i 값 그리고 j 값에 위치한 값들을 서로 바꾸어
    // 줍니다.
    while(i <= j){
        // 오름차순 경우
        // i 는 왼쪽에서 오른쪽으로 가면서 pivot값에 위치한 값보다 큰 값을 찾을때까지 계속 증가합니다.
        while(i <= end && array[pivot] >= array[i]) i++;
        // j 는 오른쪽에서 왼쪽으로 가면서 pivot값에 위치한 값보다 작은 값을 찾을때까지 계속 감소합니다.
        while(j > pivot && array[pivot] <= array[j]) j--;
        // i 그리고 j 가 엇갈린 경우
        if(i > j){
            tmp = array[j];
            array[j] = array[pivot];
            array[pivot] = tmp;
        } else{
            tmp = array[j];
            array[j] = array[i];
            array[i] = tmp;
        }
    }

    // 재귀 함수 호출
    my_algorithm::quick_sort(array, start, j - 1);
    my_algorithm::quick_sort(array, j + 1, end);
}

void my_algorithm::display_array(int* array, int size){
    for(int i = 0; i < size; i++){
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';
}
