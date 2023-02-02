#ifndef MAX_HEAP_HPP
#define MAX_HEAP_HPP
#include <iostream>
#include <vector>

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

class Max_Heap{
    private:
        std::vector<int> n;
        int size;
    public:
        Max_Heap(){
            n.resize(1);
            size = 0;
        }
        void insert(const int data){
            n.push_back(data);
            int current_index = ++size;
            // parent index formula = current_index / 2
            while(current_index != 1 && n[current_index] > n[current_index / 2]){
                swap(&n[current_index], &n[current_index / 2]);
                // update current index 
                current_index = current_index / 2;
            }
        }
        void remove_max(){
            if(size == 0){
                std::cout << "no element to remove\n";
                return;
            }

            // update index 1 value of n object to last index value of the n object
            n[1] = n[size];
            // remove the last index value of n object
            n.erase(n.end() - 1);
            // update size 
            size--;
            // start from left child index 
            int child_index = 2;
            // heapify process
            while(child_index <= size){
                // right child index formula = child_index + 1
                if(child_index < size && n[child_index] < n[child_index + 1]) child_index++;

                // if child index value is smaller than parent index value, then break while loop. 
                // otherwise swap those valuse
                // parnet index formula = child_index / 2
                if(n[child_index] < n[child_index / 2]) break;
                swap(&n[child_index], &n[child_index / 2]);

                // update child_index 
                // left child index formula from current index = child index * 2
                child_index = child_index * 2;
            }
        }
        void peek(){
            if(size == 0) std::cout << "no element to peek\n";
            else std::cout << "peek result: " << n[1] << '\n';
        }
};

#endif // MAX_HEAP_HPP