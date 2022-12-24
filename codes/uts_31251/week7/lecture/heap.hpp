#ifndef HEAP_HPP
#define HEAP_HPP
#include <vector>

class Heap{
    private:
        std::vector<int> nodes;
        int get_parent_node_index(int current_node_index){
            return (current_node_index) / 2;
        }
        int get_left_child_node_index(int parent_node_index){
            return parent_node_index * 2;
        }
        int get_right_child_node_index(int parent_node_index){
            return parent_node_index * 2 + 1;
        }
        void heapify(int current_node_index){
            if(nodes.empty() || nodes.size() == 1)
                return;
            int left_child_index = get_left_child_node_index(current_node_index);
            int right_child_index = get_right_child_node_index(current_node_index);
            // nodes.size() - left_child_index == 1 이면 right_child_index 가 없다는 의미
            while(left_child_index <= nodes.size() - 1){
                // right_child_index 가 없는 경우
                if(nodes.size() - left_child_index == 1){
                    if(nodes[current_node_index] >= nodes[left_child_index]) 
                        break;
                    else{
                        int tmp = nodes[current_node_index];
                        nodes[current_node_index] = nodes[left_child_index];
                        nodes[left_child_index] = tmp;
                        break;
                    }
                }
                // right_child_index 가 있는 경우 
                else{
                    // current_node_index 가 왼쪽, 오른쪽 자식들 보다 큰 경우
                    if(nodes[current_node_index] >= nodes[left_child_index] && nodes[current_node_index] >= nodes[right_child_index])
                        break;
                    // 왼쪽, 오른쪽 자식중 왼쪽 자식이 큰 경우
                    if(nodes[left_child_index] > nodes[right_child_index]){
                        if(nodes[current_node_index] < nodes[left_child_index]){
                            int tmp = nodes[current_node_index];
                            nodes[current_node_index] = nodes[left_child_index];
                            nodes[left_child_index] = tmp;
                            current_node_index = left_child_index;
                        }
                    }
                    // 왼쪽, 오른쪽 자식중 오른쪽 자식이 큰 경우
                    else{
                        if(nodes[current_node_index] < nodes[right_child_index]){
                            int tmp = nodes[current_node_index];
                            nodes[current_node_index] = nodes[right_child_index];
                            nodes[right_child_index] = tmp;
                            current_node_index = right_child_index;
                        }
                    }
                }
                left_child_index = get_left_child_node_index(current_node_index);
                right_child_index = get_right_child_node_index(current_node_index);
            }
        }
    public:
        Heap(){}
        ~Heap(){}
        void insert(int value){
            nodes.push_back(value); 
            int current_node_index = nodes.size() - 1; 
            int parent_node_index = get_parent_node_index(current_node_index);

            while(parent_node_index >= 0 && nodes[current_node_index] > nodes[parent_node_index]){
                int tmp = nodes[parent_node_index];
                nodes[parent_node_index] = nodes[current_node_index];
                nodes[current_node_index] = tmp;
                current_node_index = parent_node_index;
                parent_node_index = get_parent_node_index(current_node_index);
            }
        }   
        // remove the root value
        void remove(){
            if(nodes.empty())
                return;
            int last_node_index = nodes.size() - 1;
            nodes[0] = nodes[last_node_index];
            nodes.erase(nodes.end() - 1);
            heapify(0);
        } 
        // show the biggest value
        void peek(){
            if(nodes.size() > 0)
                printf("%d\n", nodes[0]);
        }
        // display all nodes
        void show(){
            for(int i = 0; i < nodes.size(); i++){
                printf("%d ", nodes[i]);
            }
            printf("\n");
        }
};
#endif // HEAP_HPP