#include <iostream>
#include "quick_sort.hpp"
#define MAX 11

int main(){
	int numbers[MAX] = {2, 1, 4, 5, 3, 7, 6, 9 , 8, 10, 2};
	std::cout << "before sorting\n";
	my_algorithm::display_array(numbers, MAX);

	my_algorithm::quick_sort(numbers, 0, MAX - 1);
	std::cout << "after sorting\n";
	my_algorithm::display_array(numbers, MAX);
	return 0;
}
