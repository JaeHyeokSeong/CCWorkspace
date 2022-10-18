#include <iostream>
#include <string>
int main(){
    std::cout << "몇번 출력할것인지 입력해주세요: ";
    std::string count = "";
    std::cin >> count;
    int time = std::stoi(count);
    for(int i=0; i < time; i++) {
        std::cout << i+1 << ": 성재혁\n";
    }
    return 0;
}