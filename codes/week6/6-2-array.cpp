#include <iostream>
using std::cout;

int main(){
    int two_d[3][2] = {
        {1,2},
        {3,4},
        {5,6}
    };
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            cout << two_d[i][j] << ' ';            
        }
        cout << '\n';
    }

    cout << "2차원 배열 주소 비교\n";
    cout << "&two_d[0][0] => " << &two_d[0][0] << '\n';
    cout << "two_d[0] => " << two_d[0] << '\n';
    cout << "two_d => " << two_d << '\n';
    return 0;
}