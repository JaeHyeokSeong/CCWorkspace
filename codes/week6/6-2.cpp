#include <iostream>
using std::cout;
int main(){
    double scores[3] = {10,20,30};
    double sum = 0, average = 0;
    for(int i = 0; i < 3; i++) {
        cout << "score: " << scores[i] << ", address: " << &scores[i] << '\n';
        sum += scores[i];
    }
    cout << "[확인] index 0의 주소랑 배열이름의 주소 => " << scores << '\n'; 
    average = sum/3;
    cout << "average: " << average << '\n';

    // char name[] = {'a', 'b', 'c'};
    char name[] = "abc";
    for(int i = 0; i < 3; i++) {
        cout << name[i];
    }
    cout << '\n';
    return 0;
}