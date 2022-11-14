/*
알고리즘 : heap sort
목표 : heap sort 알고리즘을 사용해서 아래에
정의 되어진 배열을 오름차순으로 정렬해보자.
*/
#include <iostream>
using std::cout;

#define MAX 9
void heapSort(int* array){
    for(int i = 1; i < MAX-1; i++){
        // node 인덱스 저장
        int n = i;
        do{
            // root 찾아주는 공식
            int root = (n-1)/2;

            // 만약에 자식 노드의 값이 부모인 root 노드의 값보다 크면 
            // 자식 노드의 값 그리고 root 노드의 값을 바꿔준다.
            if(array[root] < array[n]){
                int temp = array[root];
                array[root] = array[n];
                array[n] = temp;
            }
            n = root;
        } while(n != 0);
    }

    // 위에서 아래로 낼어가면 heapify algorithm 적용
    for(int i = MAX - 1; i >= 0; i--){
        /*
        맨 위에 있는 놈이랑 맨 아래에 있는
        두 값을 서로 바꿔줘야 한다.
        */
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        // 다시 heapify 실행
        int root = 0;
        int n = 1;
        while(n < i){
            n = 2 * root + 1;
            // 자식쪽에서 어디 쪽 자식이 더 큰 값을 가지고 있는지 확인하기
            if(array[n] < array[n+1] && n < i - 1){
                n++;
            }
            if(array[root] < array[n] && n < i){
                int temp = array[root];
                array[root] = array[n];
                array[n] = temp;
            }
            root = n;
        }
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
    int array[MAX] = {7, 6, 5, 8, 3, 5, 9, 1, 6};
    // [2] process
    heapSort(array);
    // [3] output
    print(array);
    return 0;
}