#include <iostream>
#include <algorithm>
using std::sort;
using std::string;
using std::cout;
using std::cin;

void input(string* a, const int length){
    for(int i = 0; i < length; i++){
        cin >> a[i];
    }
}
void print(const string* a, const int length){
    for(int i = 0; i < length; i++){
        cout << a[i] << '\n';
    }
}
bool compare(string& a, string& b){
    if(a.length() != b.length()){
        // 두개의 시리얼 넘버의 길이가 다른 경우 길이가 짧은 것은 먼저 나오게 한다
        if(a.length() < b.length()){
            return 1;
        } else{
            return 0;
        }
    }
    else {
        // 문자빼고 숫자들만 합친 값들 중에서 더 작은 값을 가진 
        // 시리얼 넘버가 먼저 나오도록 해준다.
        int a_length = 0, b_length = 0;
        
        // a 문자열에 있는 숫자의 합 계산해주기
        for(int i = 0; i < a.length(); i++){
            int temp = (int)a[i];
            // ascii code 에서 숫자는 48 57 사이의 숫자이다.
            if(temp >= 48 && temp <= 57){
                // 48을 빼줌으로써 char num -> int num 으로 바꿔준다
                a_length += (temp - 48); 
            }
        }
        // b 문자열에 있는 숫자의 합 계산해주기
        for(int i = 0; i < b.length(); i++){
            int temp = (int)b[i];
            if(temp >= 48 && temp <= 57){
                b_length += (temp - 48);
            }
        }
        // a 문자열에 있는 숫자들의 합이 b 문자열에 있는 숫자들의 합보다 작은 경우
        if(a_length < b_length){
            return 1; // 숫자들의 합이 작은 것이 먼저 나오게 한다
        }
        else if(a_length > b_length){
            return 0; 
        }
        else{
            // 만약 두 문자열의 숫자의 합이 모두 같은 경우에는 사전순으로 정렬한다
            return a < b;
        }
    }
}
int main(){
    // [1] initialise
    string sn[50];
    int length;
    // [2] input
    cin >> length;
    input(sn, length);
    // [3] process
    sort(sn, sn + length, compare);
    // [4] output
    print(sn, length);
    return 0;
}