#include <iostream>

long long a[1000001][2] = {};
long long dp(int i){
    a[0][0] = 0;
    a[1][0] = 2;
    a[2][0] = 7;
    a[2][1] = 1;
    for(int j = 3; j <= i; j++){
        a[j][1] = (a[j-1][1] + a[j-3][0]) % 1000000007;
        a[j][0] = (2*a[j-1][0] + 3*a[j-2][0] + 2*a[j][1]) % 1000000007;
    }
    return a[i][0]; 
}
int main(){
    int x;
    scanf("%d", &x);
    printf("%lld\n", dp(x));
    return 0;
}