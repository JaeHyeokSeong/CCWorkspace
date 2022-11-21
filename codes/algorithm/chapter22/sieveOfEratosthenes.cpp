#include <iostream>

void isPrimeNumbers(int* numbers, int length){
    // 2의 배수부터 마지막 수의 배수까지 진행한다
    for(int i = 2; i <= numbers[length - 1]; i++){
        if(numbers[i] == 0)
            continue;
        for(int j = i + i; j <= numbers[length - 1]; j += i){
            if(numbers[j] % j == 0)
                numbers[j] = 0;
        }
    }
}
int main(){
    // [1] initialise
    int numbers[11] = {};
    for(int i = 1; i < 11; i ++){
        numbers[i] = i;
    }
    // [2] process
    isPrimeNumbers(numbers, 11);
    // [3] output
    for(int i = 2; i < 11; i++){
        if(numbers[i] != 0)
            printf("%d ", numbers[i]);
    }
    printf("\n");
    return 0;
}