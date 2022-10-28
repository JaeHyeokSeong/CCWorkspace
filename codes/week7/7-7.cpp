#include <iostream>
using std::cout;
using std::cin;
int main(){
    int size;
    cout << "enter array size: ";
    cin >> size;
    int array[size];
    
    for(int i = 0; i < size; i++) {
        cout << "Enter a number: ";
        cin >> array[i];
    }
    cout << "result: ";
    for(int i = 0; i < size; i++) {
        cout << array[i] << " "; 
    }
    cout << '\n';
    return 0;

    // 이와 같이 실행하는 것은 좋은 방법이 아니다. 왜냐하면 stack에는 heap보다는 상대적은 작은 메모리 공간만 잡을 수 있기 때문이다.
    // 따라서 만약 사용자가 범위를 넘어서는 큰 메모리공간 할당을 요구하면 segment fault 와 같이 에러가 발생 할수도 있다.
    // 이 경운에는 heap을 사용하는 동적메모리 할당의 사용을 고려해야 한다.
}