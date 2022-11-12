/*
selection sort (선택정렬) 구현하기
가장 작은 것을 선택해서 제일 앞으로 보내기
*/
#include <iostream>
#include <time.h>
using std::cout;
using std::endl;

#define MAX 10
void selectionSort(int* nums){
    // 오름차순으로 정렬하기
    int min, min_index, temp;

    for(int i = 0; i < MAX-1; i++) {
        min = nums[i];
        min_index = i;
        for(int j = i + 1; j < MAX; j++){
            if(min > nums[j]){
                /*
                만약 min 보다 작은 값이 있다면 그 값을 
                min에다가 대입에해주고 새로운 값의 인덱스
                를 저장해 준다.
                */
                min = nums[j];
                min_index = j;
            }
        }
        // 이 단계에서 가장 작은 값을 찾았다
        // 가장 작은 값을 맨 앞에다가 대입하기
        temp = nums[i];
        nums[i] = min;
        nums[min_index] = temp;
    }
}
void print(int* nums){
    for(int i = 0; i < MAX; i++){
        cout << nums[i] << ' ';
    }
    cout << endl;
}
int main(){
    // [1] initialise
    clock_t start, end;
    double duration;
    int array[MAX] = {1,10,5,8,7,6,4,3,2,9};


    // [2] process
    start = clock();
    selectionSort(array);
    end = clock();

    // [3] output
    print(array);
    duration = (double)(end-start);
    cout << "수행 시간 : " << duration << " millisecond" << endl;
    return 0;
}