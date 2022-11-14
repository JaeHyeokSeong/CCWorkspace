/*
알고리즘 : heap sort
시간 복잡도 : O(N * logN)

heapify algorithm 시간 복잡도 : logN
총 heapify 를 해야하는 횟수 : N 번
따라서 heap sort 의 사간 복잡도 : O(N * logN)
*/
#include <iostream>
using std::cout;
#define MAX 9
void heapSort(int* array, int length){
    // 먼저 전체 트리 구조를 힙 구조로 바꿔준다.
    for(int i = 1; i < length; i++){
        int c = i;
        do{
            /*
            특정 노드의 부모 인덱스를
            알 수가 있다. 아래의 식으로
            */
            int root = (c-1)/2;
            /*
            만약 부모의 노드의 값이
            자식의 노드의 값보다 작으면
            둘이 바꿔줘야 한다.
            */
            if(array[root] < array[c]){
                int temp = array[root];
                array[root] = array[c];
                array[c] = temp;
            }
            c = root;
        }while(c != 0);
    }
    // 크기를 줄여가며 반복적으로 힙을 구성 한다
    for(int i = length - 1; i >=0; i--){
        // root 노드랑 제일 아래에 있는 노드랑 바꿔준다.
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        int root = 0;
        int c = 1;
        do {
            c = 2 * root + 1;
            // 자식 중에서 더 큰 값을 찾기
            if(array[c] < array[c+1] && c < i - 1){
                c++;
            }
            // root 보다 자식이 더 크면 교환
            if(array[root] < array[c] && c < i){
                int temp = array[root];
                array[root] = array[c];
                array[c] = temp;
            }
            root = c;
        } while(c < i);
    }
}
int main(){
    // [1] initialise
    int array[MAX] = {7, 6, 5, 8, 3, 5, 9, 1, 6};
    // [2] process
    heapSort(array, MAX);
    // [3] output
    for(int i = 0; i < MAX; i++) {
        cout << array[i] << ' ';
    }
    cout << '\n';
    return 0;
}