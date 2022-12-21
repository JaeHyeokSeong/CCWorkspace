#include <iostream>
#define MAX 10

int array[MAX] = {4, 2, 3, 1, 5, 7, 8, 6, 9, 10};

void quick_sort(int start_index, int end_index){
    if(end_index <= start_index)
        return;
    
    int pivot = start_index;
    int i = pivot + 1;
    int j = end_index;

    // i j 가 서로 엇갈리기 전까지 반복을 실행한다.
    while(i <= j){
        // 오름차순 기준
        // 오른쪽으로 가면서 pivot 값 보다 큰 값 찾기
        while(i <= end_index && array[pivot] >= array[i]){
            i++;
        }
        // 왼쪽으로 가면서 pivot 값 보다 작은 값 찾기
        while(j > start_index && array[pivot] <= array[j]){
            j--;
        }
        if(i > j){
            int tmp = array[pivot];
            array[pivot] = array[j];
            array[j] = tmp;
        } else{
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }

    quick_sort(start_index, j - 1);
    quick_sort(j + 1, end_index);
}
int main(){
    quick_sort(0, MAX-1);
    for(int i = 0; i < MAX; i++){
        std::cout << array[i] << ' '; 
    }   
    std::cout << '\n';
    return 0;
}