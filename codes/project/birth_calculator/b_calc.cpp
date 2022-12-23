#include <iostream>
#include <time.h>

int birth_calculator(int kor_age){
	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);
	int current_year = t->tm_year + 1900;
	
	return current_year - kor_age + 1;
}
int main(){
	int birth = birth_calculator(22);
	std::cout << birth << '\n';
	return 0;
}
