#include <iostream>
using std::cout;

int main(){
    int* pi = new int;
    // 0 또는 nullptr이 반환이 된다, 만약에 heap상에서 메모리가 부족한경우에
    if(pi == nullptr){
        cout << "heap에 메모리 공간 부족\n";
        return 1; // 비정상 종료시 보통은 1을 리턴 합니다.
    }
    cout << "heap에서 메모리 할당 성공\n";
    *pi = 100;
    cout << *pi << '\n';
    delete pi; // heap 상에서 메모리를 다 사용한 다음에는 반드시 사용한 메모리주소를 해제시켜줘야 한다.
    return 0;
}