#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

namespace my_algorithm {
    /*
    parameter
    [1] 정렬하고 싶은 배열의 주소를 입력합니다.
    [2] 위에서 입력한 배열의 시작 인덱스를 입력합니다.
    [3] 위에서 입력한 배열의 마지막 인덱스를 입력합니다.

    return 
    [1] void
    */
    void quick_sort(int* array, int start, int end);
    
    /*
    parameter 
    [1] 출력하고 싶은 배열의 주소를 입력합니다.
    [2] 위에서 입력한 배열의 사이즈(총 요소의 수)를 입력합니다.

    return
    [1] void
    */
    void display_array(int* array, int size);
}

#endif // QUICK_SORT_HPP
