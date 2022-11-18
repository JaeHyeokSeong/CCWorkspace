/*
날짜 : 18일 11월 2022년
주제 : stack 자료형 구조 구현하기
구현 기능 : stack 의 기본적인 메서드들인 push, pop, top, size 등의 기능들을 구현하기
*/
#include <iostream>
#include <vector>
#include "stack.hpp"
using std::cin;
using std::cout;

int main(){
	Stack<int> s;
	int i = 0;
	do{
		cout << "\n1 - push, 2 - pop, 3 - top, 4 - size, 5 - exit\n\n";
		cin >> i;
		if(i == 1){
			int value;
			cout << "enter a value : ";
			cin >> value;
			s.push(value);
		}
		else if(i == 2){
			try{
				s.pop();
			} catch(std::out_of_range& e){
				cout << "예외 발생 : " << e.what() << '\n';
			}
		}
		else if(i == 3){
			try{
				cout << "top한 결과 : " << s.top() << '\n';
			} catch(std::out_of_range& e){
				cout << "예외 발생 : " << e.what() << '\n';
			}
		}
		else if(i == 4){
			cout << "사이즈 : " << s.size() << '\n';
		}
		else if(i == 5){
			cout << "종료\n";
		}
		else {
			cout << "잘못된 입력\n";
		}
	}while(i != 5);
	return 0;
}
