/*
작성일: 2022년 12월 25일

목표: complete binary tree에서 binary heap (max heap)의 
원리를 알아보도록 하자.

주의할점: max heap 이란 부모 노드가 자식 노드들 보다 큰 것을 의미
하는 것이다.

참고한 자료들: 
https://blog.naver.com/ndb796/221228342808
https://yoongrammer.tistory.com/80
https://code-lab1.tistory.com/12
*/
#include <iostream>
#include "heap.hpp"

int main(){
    Heap heap;
    heap.insert(7);
    heap.insert(6);
    heap.insert(5);
    heap.insert(8);

    heap.show();
    heap.remove();
    heap.show();
    heap.insert(10);
    heap.show();
    heap.remove();
    heap.remove();
    heap.show();
    heap.remove();
    heap.show();
    heap.remove();
    heap.show();
}