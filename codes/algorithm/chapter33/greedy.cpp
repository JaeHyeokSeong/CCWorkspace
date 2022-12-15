#include <iostream>
using std::cin;
using std::cout;

void greedy(int change){
	/*
	 * 무조건 큰 숫자의 화폐 부터 골라서 거슬러
	 * 주면 된다
	 * - 화폐 단위
	 * 500, 100, 50, 10
	 * */
	int fh_count = 0, oh_count = 0, fy_count = 0, tn_count = 0;
	fh_count += change / 500;
	change %= 500;
	oh_count += change / 100;
	change %= 100;
	fy_count += change / 50;
	change %= 50;
	tn_count += change / 10;
	change %= 10;

	cout << "결과 => 오백원: " << fh_count << ", 백원: " << 
	oh_count << ", 오십원: " << fy_count << ", 십원: " << tn_count << '\n';
}
int main(){
	int cash;
	cin >> cash;
	greedy(cash);
	return 0;
}
