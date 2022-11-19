/*
reference : https://charles098.tistory.com/10
*/
#include <iostream>
#include "change_traversal_format.hpp"
#include "calculate_postorder_expression.hpp"
using std::cout;

int main(){
	string postorder_result = change_traversal_to_postorder("4+8*(3-5)");
	cout << "postorder expression : " << postorder_result << '\n';
	double expression_result = calculate_postorder(postorder_result);
	cout << "result : " << expression_result << '\n';
	return 0;
}
