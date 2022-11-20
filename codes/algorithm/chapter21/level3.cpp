#include <iostream>

int a[31] = {};
int da(int i){
    if(i == 0)
        return 1;
    if(i == 1)
        return 0;
    if(i == 2)
        return 3;
    if(a[i] != 0)
        return a[i];
    a[i] = 3 * da(i - 2);
    if(i > 3 && i % 2 == 0){
        for(int j = 4; j <= i; j+=2){
            a[i] += 2*da(i - j);
        }
    }
    return a[i];
}
int main(){
    int x;
    scanf("%d", &x);
    printf("%d\n", da(x));
    return 0;
}