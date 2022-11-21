#include <iostream>
#define MAX 10001
void isPrimeNumbers(int* numbers){
    for(int i = 2; i < MAX; i++){
        if(numbers[i] == 0)
            continue;
        for(int j = i + i; j < MAX; j += i){
            numbers[j] = 0;
        }
    }
}
int main(){
    // [1] initialise
    int numbers[MAX] = {};
    for(int i = 1; i < MAX; i++){
        numbers[i] = i;
    }
    // [2] process
    isPrimeNumbers(numbers);
    // [3] output
    for(int i = 2; i < MAX; i++){
        if(numbers[i] == 0)
            continue;
        printf("%d ", numbers[i]);
    }
    printf("\n");
    return 0;
}