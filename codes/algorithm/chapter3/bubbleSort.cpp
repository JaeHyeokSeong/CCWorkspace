/*
2022년 11월 12일 토요일
bubble sort (버블 정렬) 구현하기
가장 가까운 수끼리 비교한 후 그 중에서 가장 작은 수를 
앞으로 보내는 정렬을 버블 정렬 이라고 한다
*/
#include <iostream>
using std::cout;
using std::endl;

#define MAX 10

void bubbleSort(int* nums){
    int temp;
    for(int i = 0; i < MAX - 1; i++){
        for(int j = 0; j < MAX -1 - i; j++) {
            if(nums[j] > nums[j+1]){
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
}
void print(int* nums){
    for(int i = 0; i < MAX; i++) {
        cout << nums[i] << ' ';
    }
    cout << endl;
}
int main(){
    // [1] initialise
    int numbers[MAX] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

    // [2] process
    bubbleSort(numbers);

    // [3] output
    print(numbers);

    return 0;
}