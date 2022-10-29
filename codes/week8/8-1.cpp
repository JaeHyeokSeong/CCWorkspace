#include <iostream>
#include "cat.hpp"
using std::cout;
using std::cin;
int main(){
    // Cat cat1(2);
    // Cat* p; // 이 과정에서 객체가 생성되는 것은 아니다.
    // p = &cat1;
    // p->setAge(10);
    // cout << cat1.getAge() << '\n';
    // cat1.meow();


    // 동적 메모리 할당 (heap)
    // Cat* pCat1 = new Cat;
    // cout << pCat1->getAge() << '\n';

    int size = 0;
    cout << "고양이 수 입력: ";
    cin >> size;
    Cat* pCats = new Cat[size]; // 배열의 생성과 동시에 각 인덱스에 객체가 생성되어진다
    if(pCats == nullptr){
        cout << "heap에 메모리 공간 부족\n";
        return 1;
    }

    for(int i = 0; i < size; i++) {
        cout << pCats[i].getAge() << '\n';
    }

    delete []pCats;
}