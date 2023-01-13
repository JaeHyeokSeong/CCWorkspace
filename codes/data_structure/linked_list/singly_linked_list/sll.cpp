#include "sll.hpp"

void menu(){
	std::cout << "1 - insert, 2 - remove, 3 - display, 4 - exit\n";
}
int read_input(){
	int input;
	std::cin >> input;
	return input;
}

int main(){
	SLL sll;
	int input = 0;

	do{
		menu();
		input = read_input();

		if(input == 1){
			std::cout << "삽입할 값을 입력해 주세요: ";
			sll.insert_front(read_input());
		}
		else if(input == 2){
			std::cout << "삭제할 값을 입력해 주세요: ";
			sll.remove(read_input());
		} 
		else if(input == 3){
			sll.display();
		}
		else if(input == 4){
			std::cout << "종료\n";
		}
		else{
			std::cout << "잘못된 입력입니다.\n";
		}
	} while(input != 4);

	return 0;
}
