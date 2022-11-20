#include <iostream>

int a[1001] = {};
int tile(int i){
    if(i==1)
        return 1;
    if(i==2)
        return 3;
    if(a[i] != 0)
        return a[i];
    return a[i] = (tile(i-1) + 2*tile(i-2)) % 10007;
}
int main(){
    int x;
    scanf("%d", &x);
    printf("%d\n", tile(x));
    return 0;
}