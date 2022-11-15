#include <iostream>

void counting_sort(int* array, const int length){
    for(int i = 0; i < length; i++){
        int temp;
        scanf("%d", &temp);
        array[temp]++;
    }
}
void print(int* array){
    for(int i = 0; i < 10001; i++){
        for(int j = 0; j < array[i]; j++){
            printf("%d\n", i);
        }
    }
}
int main(){
    // [1] initialise
    int counted_array[10001] = {0};
    int length;
    // [2] input
    scanf("%d", &length);
    // [3] process
    counting_sort(counted_array, length);
    // [4] output
    print(counted_array);
    return 0;
}