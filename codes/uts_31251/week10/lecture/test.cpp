#include <iostream>
#include <cassert>
int get_score(){
    int score;
    std::cout << "점수를 입력해주세요 : ";
    assert(score >= 0); 
    // score가 0보다 작은면 assert함수 실행
    std::cin >> score;
    return score;
}
int main(){
    while(1){
        std::cout << "입력되어진 점수 : " << get_score() << '\n';
    }
    return 0;
}