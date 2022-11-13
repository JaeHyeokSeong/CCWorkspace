#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*
input : 3 1 2
output : 1 2 3
*/
#define MAX 3
void quickSort(int* array, int start_index, int end_index){
    if(start_index >= end_index){
        return;
    }

    int pivot = start_index;
    /*
    오름차순일때 왼쪽에서 오른쪽으로 가면서 피벗 값보다
    큰값을 찾고 이때 큰 값의 인덱스 값을 변수 i에 저장
    */
    int i = start_index + 1;
    /*
    오름차순일때 오른쪽에서 왼쪽으로 가면서 피벗 값보다 
    작은값을 찾고 이때 그 값의 인덱스 값을 변수 j에 저장
    */
    int j = end_index;
    int temp;
    // 분할
    while(i <= j){
        while(array[pivot] > array[i] && i <= end_index){
            i++;
        }
        while(array[pivot] < array[j] && j > start_index){
            j--;
        }

        // 교차됨
        // pivot 값이랑 작은 값이랑 교체
        if(i > j){
            temp = array[pivot];
            array[pivot] = array[j];
            array[j] = temp; 
        } else{
            /*
            아직 교차되어지지 않았을때에는 큰 값 그리고 작은 값을
            서로 교체 해줘야 한다.
            */
           temp = array[i];
           array[i] = array[j];
           array[j] = temp;
        }
    }

    quickSort(array, start_index, j-1);
    quickSort(array, j+1, end_index);
}
void print(int* array){
    for(int i = 0; i < MAX; i++){
        cout << array[i] << ' ';
    }
    cout << endl;
}
void read(int* array){
    for(int i = 0; i < MAX; i++){
        cin >> array[i];
    }
}
int main(){
    int array[MAX];
    read(array);
    quickSort(array, 0, MAX-1);
    print(array);
    return 0;
}