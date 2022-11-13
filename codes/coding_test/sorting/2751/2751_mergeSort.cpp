#include <iostream>
using std::cout;
using std::cin;


int sorted_array[1000001];
void merge(int* array, int start_index, int mid_index, int end_index){
    int i = start_index;
    int j = mid_index + 1;
    int k = start_index;

    while(i <= mid_index && j <= end_index){
        if(array[i] > array[j]){
            sorted_array[k] = array[j];
            j++;
        } else {
            sorted_array[k] = array[i];
            i++;
        }
        k++;
    }

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

    for(int i = start_index; i <= end_index; i++){
        array[i] = sorted_array[i];
    }
}
void mergeSort(int* array, int start_index, int end_index){
    if(start_index < end_index){
        int mid_index = (start_index + end_index) / 2;
        mergeSort(array, start_index, mid_index);
        mergeSort(array, mid_index + 1, end_index);
        merge(array, start_index, mid_index, end_index);
    }
}
void read_input(int* array, int length){
    for(int i = 0; i < length; i++) {
        cin >> array[i];
    }
}
void print(int* array, int length){
    for(int i = 0; i < length; i++){
        cout << array[i] << '\n';
    }
}
int main(){
    // [1] initialise
    int array[1000001];
    int length;
    // [2] input
    cin >> length;
    read_input(array, length);
    // [3] process
    mergeSort(array, 0, length-1);
    // [4] output
    print(array, length);
    return 0;
}