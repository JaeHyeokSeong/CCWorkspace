/*
알고리즘 : quick sort (퀵 정렬)

문제 : 다음의 숫자들을 오름차순으로 정렬하는 프로그램을 작성하세요
1 10 5 8 7 6 4 3 2 9
*/
#include <iostream>
using std::cout;
using std::endl;

#define MAX 10
void quickSort(int* array, int start_index, int end_index){
    /*
    start_index 그리고 end_index 가 같으면 
    원소가 1개 이라는 의미 이다. 즉 더이상 나눌 것이
    없다는 의미이다.
    */
    if(start_index >= end_index){
        return;
    }

    // 분할 단계

    // pivot 값은 첫번째 값으로 많이 선택되어진다
    int pivot = start_index;
    /*
    i 는 왼쪽에서 오른쪽 즉 큰 값의 인덱스 값을 
    저장하기 위해서 사용되어지는 변수이다.
    */
    int i = pivot + 1;
    /*
    j 는 오른쪽에서 왼쪽 즉 작은 값의 인덱스 값을
    저장하기 위해서 사용되어지는 변수이다.
    */
    int j = end_index;
    // 값을 바꿀때 사용되어지는 임시 변수 temp
    int temp;

    /*
    엇갈리기 이전까지 계속 반복해준다
    */
    while(i <= j){
        /*
        [큰 값 찾기]
        만약 피벗 값 보다 값이 작다면 큰 값을 찾기 위해서
        1씩 증가시키면서 계속 찾아본다.
        */
        while(array[i] <= array[pivot] && i <= end_index){
            i++;
        }
        while(array[j] >= array[pivot] && j > start_index){
            j--;
        }
        // 엇갈린 상태
        if(i > j){
            // 작은 값이랑 pivot 값이랑 자리 바꿔주기
            temp = array[pivot];
            array[pivot] = array[j];
            array[j] = temp;
        } else{
            // 엇갈리지 않은 상태
            // 큰 값 작은 값 바꿔주기
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }

    quickSort(array, start_index, j-1);
    quickSort(array, j+1, end_index);
}
void descendingOrder_quickSort(int* array, int start_index, int end_index){
    if(start_index >= end_index){
        return;
    }

    int pivot = start_index;
    /*
    왼쪽에서 오른쪽으로 가면서 pivot 값보다
    작은 값의 인덱스를 i에 저장
    */
    int i = pivot + 1;
    /*
    오른쪽에서 왼쪽으로 가면서 pivot 값보다
    큰 값의 인덱스를 j에 저장
    */
    int j = end_index;
    int temp;
    while(i <= j){

        while(array[i] >= array[pivot] && i <= end_index){
            i++;
        }
        while(array[j] <= array[pivot] && start_index < j){
            j--;
        }

        if(i > j){
            temp = array[pivot];
            array[pivot] = array[j];
            array[j] = temp;
        } else{
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    descendingOrder_quickSort(array, start_index, j-1);
    descendingOrder_quickSort(array, j+1, end_index);
}
void print(int* array){
    for(int i = 0; i < MAX; i++){
        cout << array[i] << ' ';
    }
    cout << endl;
}
int main(){
    // [1] initialise
    int array[MAX] = {10, 1, 5, 8, 7, 6, 4, 3, 2, 9};

    // ascending order
    // [2] process 
    quickSort(array, 0, MAX-1);
    
    // [3] output
    cout << "ascending order" << endl;
    print(array);

    // descending order
    // [2] process
    descendingOrder_quickSort(array, 0, MAX-1);

    // [3] output
    cout << "descending order" << endl;
    print(array);
    return 0;
}