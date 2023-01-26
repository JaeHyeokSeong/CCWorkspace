#ifndef HEAP_1_HPP
#define HEAP_1_HPP

#include <iostream>
#include <vector>

int get_parent_node_index(const int current_node_index){
    return current_node_index / 2;
}
int get_left_child_node_index(const int current_node_index){
    return current_node_index * 2;
}
int get_right_child_node_index(const int current_node_index){
    return current_node_index * 2 + 1;
}

class Min_Heap{
    private:
        std::vector<int> nodes;
        int size;
    public:
        Min_Heap(){
            // index 1 부터 시작해야하므로 사이즈를 조정해준다
            nodes.resize(1);
            size = 0;
        }
        void insert(const int data){
            /*
            1. 새로운 노드를 힙의 마지막 노드에 이어서 삽입한다. (배열의 마직막에 원소 추가)
            2. 새로운 노드를 부모 노드와 비교해서 교환해야 한다면 힙의 성질을 만족 할 때까지 
            (Min Heap: 부모 노드가 자식 노드들 보다 작아야 한다.)
            */
            nodes.push_back(data);
            int current_node_index = ++size;
            while(current_node_index != 1 && nodes[current_node_index] < nodes[get_parent_node_index(current_node_index)]){
                int tmp = nodes[current_node_index];
                nodes[current_node_index] = nodes[get_parent_node_index(current_node_index)];
                nodes[get_parent_node_index(current_node_index)] = tmp;
                current_node_index = get_parent_node_index(current_node_index);                                 
            }
        }
        void remove_min(){
            if(size == 0){
                std::cout << "no element to remove\n";
                return;
            }

            /*
            1. root 노드의 갑이랑 가장 마지막 노드의 값을 서로 바꾼다.
            2. 가장 마지막 노드를 삭제한다.
            3. heap의 조건에 맞게 heapify를 실행한다.
            */
            int min_value = nodes[1];
            nodes[1] = nodes[size];
            nodes[size] = min_value;
            size--;

            nodes.erase(nodes.end() - 1);

            int child_node_index = 2;
            while(child_node_index <= size){
                // 오른쪽 자식이 있는 경우, 왼쪽 오른쪽 더 작은 값을 가지고 있는 자식을 찾는다 (min heap 기준)
                if(child_node_index < size && nodes[child_node_index] > nodes[child_node_index + 1])
                    child_node_index++;
                // 부모 값이랑 비교
                if(nodes[get_parent_node_index(child_node_index)] < nodes[child_node_index]) break;
                    
                int tmp = nodes[get_parent_node_index(child_node_index)];
                nodes[get_parent_node_index(child_node_index)] = nodes[child_node_index];
                nodes[child_node_index] = tmp;
                child_node_index = get_left_child_node_index(child_node_index);
            }
        }
        void peek(){
            if(size == 0){
                std::cout << "no element to peek\n";
                return;
            }

            std::cout << nodes[1] << '\n';
        }
        void show(){
            if(size == 0){
                std::cout << "no element to show\n";
                return;
            }

            for(int i = 1; i < nodes.size(); i++){
                std::cout << nodes[i] << ' ';
            }
            std::cout << '\n';
        }
};

#endif // HEAP_1_HPP