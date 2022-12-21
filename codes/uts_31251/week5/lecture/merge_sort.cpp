#include <iostream>
#define MAX 10

int sorted_array[MAX];

void merge_sort(int array[], int start_index, int mid_index, int end_index){
    int i = start_index;
    int j = mid_index + 1;
    int k = start_index;

    // 오름차순
    while(i <= mid_index && j <= end_index){
        if(array[i] > array[j]){
            sorted_array[k++] = array[j++];
        } else{
            sorted_array[k++] = array[i++];
        }
    }

    // 내림차순
    // while(i <= mid_index && j <= end_index){
    //     if(array[i] > array[j]){
    //         sorted_array[k++] = array[i++];
    //     } else{
    //         sorted_array[k++] = array[j++];
    //     }
    // }

    if(i > mid_index){
        while(j <= end_index){
            sorted_array[k++] = array[j++];
        }
    } 
    if(j > end_index){
        while(i <= mid_index){
            sorted_array[k++] = array[i++];
        }
    }

    for(k = start_index; k <= end_index; k++){
        array[k] = sorted_array[k];
    }
}
void merge(int array[], int start_index, int end_index){
    if(start_index < end_index){
        int mid_index = (start_index + end_index) / 2;
        merge(array, start_index, mid_index);
        merge(array, mid_index + 1, end_index);
        merge_sort(array, start_index, mid_index, end_index);
    }
}
int main(){
    int array[MAX] = {4, 2, 3, 1, 5, 7, 8, 6, 9, 10};
    merge(array, 0, MAX - 1);
    for(int i = 0; i < MAX; i++){
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';
    return 0;
}