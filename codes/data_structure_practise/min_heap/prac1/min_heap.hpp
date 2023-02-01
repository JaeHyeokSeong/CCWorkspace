#ifndef MIN_HEAP_HPP
#define MIN_HEAP_HPP
#include <iostream>
#include <vector>

int get_parent_index(int index){
	return index / 2;
}

void swap(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

class Min_Heap{
	private:
		std::vector<int> n;
		int size;
	public:
		Min_Heap(){
			n.resize(1);
			size = 0;
		}
		void insert(const int data){
			n.push_back(data);
			int current_index = ++size;
			while(current_index != 1 && n[current_index] < n[get_parent_index(current_index)]){
				swap(&n[current_index], &n[get_parent_index(current_index)]);
				current_index = get_parent_index(current_index);
			}
		}
		void remove_min(){
			if(size == 0){
				std::cout << "no element to remove\n";
				return;
			} 
			n[1] = n[size--];
			n.erase(n.end() - 1);
			int c_i = 2;
			while(c_i <= size){
				if(c_i < size && n[c_i] > n[c_i + 1]) ++c_i;
				if(n[get_parent_index(c_i)] <= n[c_i]) break;
				swap(&n[get_parent_index(c_i)], &n[c_i]);
				c_i *= 2;
			}
		}
		void peek(){
			if(size == 0) std::cout << "no element to peek\n";
			else std::cout << n[1] << '\n';			
		}
		void display_all(){
			for(int i = 1; i <= size; i++){
				std::cout << n[i] << ' ';
			}
			std::cout << '\n';
		}
};

#endif // MIN_HEAP_HPP
