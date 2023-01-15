#include <iostream>
#include <stdlib.h>
#include "dll-1.hpp"

// Dll class
// - 구현된 함수들 : add_node_front(), add_node_back(), get_node_at(), remove_node_at(),
// insert_node_at_after(), display_nodes()

void menu(){
	std::cout << "1 - add_node_front(), ";
	std::cout << "2 - add_node_back(), ";
	std::cout << "3 - remove_node_at(), ";
	std::cout << "4 - insert_node_at_after(), ";
	std::cout << "5 - display_nodes(), ";
	std::cout << "6 - clear, ";
	std::cout << "7 - exit\n";
}

int read_input(std::string txt = ""){
	int input;
	std::cout << txt;
	std::cin >> input;
	return input;
}

int main(){
	int input = 0;
	Dll dll;
	do{
		menu();
		input = read_input();
		if(input == 1) dll.add_node_front(read_input("enter data: "));
		else if(input == 2) dll.add_node_back(read_input("enter data: "));
		else if(input == 3) dll.remove_node_at(read_input("enter index: "));
		else if(input == 4) dll.insert_node_at_after(read_input("enter index: "), read_input("enter data: "));
		else if(input == 5) dll.display_nodes();
		else if(input == 6) system("clear");
		else if(input == 7) std::cout << "finished\n";
		else std::cout << "invalid input\n";
	}while(input != 7);
	return 0;
}
