/*
참고자료 : https://www.youtube.com/watch?v=iSdEHxVJ5vk
*/
#include <iostream>
#include "dll.hpp"

void menu(){
	std::cout << "1 - add_node_front, 2 - add_node_back, 3 - insert_node_at_after, 4 - remove_node_at, 5 - display, 6 - count, 7 - exit\n";
}

int read_input(const char* text){
	std::cout << text;
	int input;
	std::cin >> input;
	return input;
}

int main(){
	int input = 0;
	Dll dll;

	do{
		menu();
		input = read_input("");

		if(input == 1) dll.add_node_front(read_input("enter data: "));
		else if(input == 2) dll.add_node_back(read_input("enter data: "));
		else if(input == 3) dll.insert_node_at_after(read_input("enter data: "), read_input("enter index: "));
		else if(input == 4) dll.remove_node_at(read_input("enter index: "));
		else if(input == 5) dll.display();
		else if(input == 6) std::cout << dll.get_count() << '\n';
		else if(input == 7) std::cout << "finished\n";
		else std::cout << "invalid input\n";

	}while(input != 7);
	return 0;
}
