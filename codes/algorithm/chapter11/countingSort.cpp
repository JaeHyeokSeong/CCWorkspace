/*
알고리즘 : couting sort (계수 정렬)
시간 복잡도 : O(logN) 
설명 : counting sort 를 사용하기 위해서는
데이터의 범위를 알고 있는경우에만 counting sort를
사용할 수 있다.
*/
#include <iostream>
using std::cout;

int sortedArray[5] = {0,0,0,0,0};
void countingSort(int* array){
    /*
    1 이 나온경우 index 0을 증가시켜주자
    2 가 나온경우 index 1을 증가시켜주자
    */
    
    for(int i = 0; i < 30; i++){
        int n = array[i];
        sortedArray[n-1]++;
    }
}
void print(){
    for(int i = 0; i < 5; i++){
        int n = i + 1;
        int count = sortedArray[i];
        for(int j = 0; j < count; j++){
            cout << n << ' ';
        }
    }
    cout << '\n';
}
int main(){ 
    // [1] initialise
    // 1 부터 5까지들의 수들
    int array[30] = {1,3,2,4,3,2,5,3,1,2,3,4,4,3,5,1,2,3,5,2,3,1,4,3,5,1,2,1,1,1};
    // [2] process
    countingSort(array);
    // [3] output
    print();
    return 0;
}