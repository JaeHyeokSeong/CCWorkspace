/*
2022년 11월 12일 토요일
알고리즘 : insertion sort (삽입 정렬)

구현 : 필요할때만 값의 위치를 바꾼다 / 앞에 있는 값들은 정렬되어져있다고 가정을 한다
*/
#include <iostream>
using std::cout;
using std::endl;

#define MAX 10
void insertionSort(int* array){
    for(int i = 0; i < MAX - 1; i++){
        int j = i;
        while(j >= 0 && array[j] > array[j+1]){
            int temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
            j--;
        }
    }
}
void descendingOrder_insertionSort(int* array){
    for(int i = 0; i < MAX - 1; i++){
        int j = i;
        while(j >= 0 && array[j] < array[j+1]){
            int temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
            j--;
        }
    }
}
int main(){
    // [1] initialise
    int array[MAX] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
    // [2] process
    // insertionSort(array);
    descendingOrder_insertionSort(array);
    // [3] output
    for(int i = 0; i < MAX; i++) {
        cout << array[i] << ' ';
    }
    cout << endl;
    return 0;
}