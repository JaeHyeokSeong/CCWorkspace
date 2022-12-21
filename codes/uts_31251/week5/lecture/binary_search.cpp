#include <iostream>
#define MAX 10
int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 8, 10};

int binary_search(int target_value, int length){
    int start_index = 0;
    int end_index = length - 1;
    int found_target_index = -1;

    while(start_index <= end_index){
        int mid_index = (start_index + end_index) / 2;
        // 값을 찾은 경우
        if(array[mid_index] == target_value){
            found_target_index = mid_index;
            break;
        }
        else{
            if(array[mid_index] > target_value){
                end_index = mid_index - 1;
            } else{
                start_index = mid_index + 1;
            }
        }
    }
    
    return found_target_index;
}
int main(){
    int target_value = 0;
    std::cout << "enter target value: ";
    std::cin >> target_value;
    int found_index = binary_search(target_value, MAX);
    if(found_index != -1){
        std::cout << "found at index: " << found_index << '\n';
    } else{
        std::cout << "target value: " << target_value << " NOT FOUND\n";
    }
    return 0;
}