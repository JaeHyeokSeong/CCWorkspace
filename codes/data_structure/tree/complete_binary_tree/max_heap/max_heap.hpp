#ifndef MAX_HEAP
#define MAX_HEAP

#include <iostream>
#include <vector>

int get_parent_index(const int index){
    return index / 2;
}

int get_left_child_index(const int index){
    return index * 2;
}

int get_right_child_index(const int index){
    return index * 2 + 1;
}

class Max_Heap{
    private:
        std::vector<int> nodes;
        int size;
    public:
        Max_Heap(){
            nodes.resize(1);
            size = 0;
        }
        void insert(const int key){
            nodes.push_back(key);
            int index = ++size;

            while(index != 1 && nodes[index] > nodes[get_parent_index(index)]){
                int tmp = nodes[index];
                nodes[index] = nodes[get_parent_index(index)];
                nodes[get_parent_index(index)] = tmp;
                index = get_parent_index(index);
            }
        }
        void remove_max(){
            if(size == 0){
                std::cout << "no element to remove\n";
                return;
            }

            int tmp = nodes[1];
            nodes[1] = nodes[size];
            nodes[size] = tmp;

            nodes.erase(nodes.end() - 1);
            size--;

            int child = 2;
            while(child <= size){
                if(child < size && nodes[child] < nodes[child + 1]) child++;

                if(nodes[get_parent_index(child)] > nodes[child]) break;

                int tmp = nodes[get_parent_index(child)];
                nodes[get_parent_index(child)] = nodes[child];
                nodes[child] = tmp;

                child = get_left_child_index(child);
            }
        }
        void peek() const{
            if(size == 0){
                std::cout << "no element to peek\n";
                return;
            }
            std::cout << nodes[1] << '\n';
        }
        void show() const{
            if(size == 0){
                std::cout << "no element to show\n";
                return;
            }

            for(int i = 1; i <= size; i++){
                std::cout << nodes[i] << ' ';
            }
            std::cout << '\n';
        }
};

#endif // MAX_HEAP