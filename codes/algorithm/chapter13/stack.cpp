/*
자료구조 : stack
개념 : stack 은 Last in First out 이라는 특징을 가지고 있다.
*/
#include <iostream>
#include <stack>

using std::stack;
using std::cout;

int main(){
    stack<int> s;
    s.push(7);
    s.push(5);
    s.push(4);

    s.pop(); // stack 구조상에서 가장 위에있는 데이터를 삭제한다
    while(!s.empty()){
        cout << s.top() << '\n';
        s.pop();
    }
	return 0;
}
