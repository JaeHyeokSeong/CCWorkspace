/*
problem : 10 개의 동전중에 1개의 동전이 가짜 동전 (무게가 가볍다)이다. 이때 가짜 동전의 index 위치를 구하시오
*/
#include <iostream>
#include "coin.hpp"
#define MAX 10

int find_fake_coin(Coin* coins){
    int fake_coin_index = -1;
    
    for(int i = 0; i < MAX - 1; i++){
        if(coins[i].weigth != coins[i + 1].weigth){
            if(coins[i].weigth < coins[i + 1].weigth)
                fake_coin_index = i;
            else    
                fake_coin_index = i + 1;
            break;
        }
    }
    return fake_coin_index;
}
int main(){
    // [1] input
    Coin coins[MAX] = {10, 10, 10, 10, 5, 10, 10, 10, 10, 10};
    // [2] process
    int found_fake_coin_index = find_fake_coin(coins);
    // [3] output
    std::cout << found_fake_coin_index << '\n';
    return 0;
}