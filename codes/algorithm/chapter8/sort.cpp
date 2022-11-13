#include <iostream>
#include <algorithm>

using std::cout;
using std::sort;

int main(){
    int a[10] = {9, 3, 5, 4, 1, 10, 8, 6, 7, 2};
    sort(a, a + 10);
    for(int i = 0; i < 10; i++) {
        cout << a[i] << ' '; 
    }
    cout << '\n';
    return 0;
}