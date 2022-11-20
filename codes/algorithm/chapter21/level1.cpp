#include <iostream>

int da[1001] = {};
int solve(int i){
    if(i == 1)
        return 1;
    if(i == 2)
        return 2;
    if(da[i] != 0)
        return da[i];
    return da[i] = (solve(i-1) + solve(i-2)) % 10007;
}
int main(){
    int a;
    scanf("%d", &a);
    printf("%d\n", solve(a));
    return 0;   
}