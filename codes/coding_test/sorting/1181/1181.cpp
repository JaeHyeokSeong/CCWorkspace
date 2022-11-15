#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::cin;
using std::vector;
using std::sort;
using std::string;

vector<string> readInput(int length){
    vector<string> v(length);
    for(int i = 0; i < length; i++){
        cin >> v[i];
    }
    return v;
}
/*
조건에 따라 정렬하여 단어들을 출력한다. 단, 같은 
단어가 여러 번 입력된 경웨는 한 번씩만 출력한다.
*/
void print(vector<string>& v){
    for(int i = 0; i < v.size(); i++){
        if(i != 0){
            // index 0 일때는 제외하고 
            // 그다음부터 출력할때 만약에
            // 이미 사전에 출력되었다면 출력하지
            // 말고 그 다음 인덱스로 넘어간다.
            if(v[i-1] == v[i]){
                continue;
            }
        }
        cout << v[i] << '\n';
    }
}
bool compare(string v1, const string v2){
    if(v1.length() == v2.length()){
        return v1 < v2;
    } else{
        return v1.length() < v2.length();
    }
}
int main(){
    // [1] initialise
    int length;
    // [2] input
    cin >> length;
    vector<string> v = readInput(length);
    // [3] process
    sort(v.begin(), v.end(), compare);
    // [4] output
    print(v);
    return 0;
}