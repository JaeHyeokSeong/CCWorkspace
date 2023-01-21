#include <iostream>
#include <vector>

void print(const std::vector<int> a){
	for(int i = 0; i < a.size(); i++){
		std::cout << a[i] << ' ';
	}
	std::cout << '\n';
}
int main(){
	std::vector<int> a;
	a.push_back(1);
	a.push_back(2);

	std::cout << a.size() << '\n';
	print(a);

	a.resize(4);
	print(a);

	a.resize(10, -1);
	print(a);
	return 0;
}
