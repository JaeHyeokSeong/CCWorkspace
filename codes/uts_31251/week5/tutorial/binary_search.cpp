/*
binary search
time complexity : O(logn);
*/
#include <iostream>

int binary_search(int array[], int length, int target_value){
    int start_index = 0;
    int end_index = length - 1;
    int mid_index;
    int found_target_value_index = -1;

    while(start_index <= end_index){
        mid_index = (start_index + end_index) / 2;
        if(array[mid_index] == target_value)
            return mid_index;

        if(array[mid_index] > target_value)
            end_index = mid_index - 1;
        else    
            start_index = mid_index + 1;    
    }

    return -1;
}
int main(){
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int index = binary_search(array, 10, 9);
    if(index != -1){
        std::cout << "found at index " << index << '\n';
    } else{
        std::cout << "not found\n";
    }
    return 0;
}