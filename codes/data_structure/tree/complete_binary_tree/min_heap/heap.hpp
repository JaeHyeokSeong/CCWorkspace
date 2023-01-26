#ifndef HEAP_HPP
#define HEAP_HPP

/*
heap 설명: heap 자료형 구조는 완전 이진 트리를 사용하기 때문에 선형자료형 구조를 가지는 배열, 벡터, 리스트등과 같이
연결형 자료형 구조를 사용하여서 구현 할 수 있다. 여기에서는 vector를 통하여서 구현해 볼 것이다.

참고자료: 
    [1] https://code-lab1.tistory.com/12
*/
#include <iostream>
#include <vector>

// 부모노드의 index 알아오기
int get_parent_node_index(const int& child_node_index){
    return child_node_index / 2;
}

// 왼쪽 자식 노드 index 알아오기
int get_left_child_node_index(const int& parent_node_index){
    return parent_node_index * 2;
}

// 오른쪽 자식 노드 index 알아오기
int get_right_child_node_index(const int& parent_node_index){
    return parent_node_index * 2 + 1;
}

// Min Heap
class Min_Heap{
    private:
        std::vector<int> vec;
        int num_elements;
    public:
        Min_Heap(){
            num_elements = 0;
            // index 1 부터 시작 하기 위해서
            vec.resize(1); 
        }
        ~Min_Heap(){}
        void insert(const int& key){
            // 마지막 노드에 이어서 삽입한다
            vec.push_back(key);
            // 현재 index
            int current_index = ++num_elements;
            // 부모노드가 자식 노드들 보다 값이 작아야 한다
            while(current_index != 1 && key < vec[get_parent_node_index(current_index)]){
                // 자식 노드랑 부모 노드의 값을 교환 해준다
                int tmp = vec[get_parent_node_index(current_index)];
                vec[get_parent_node_index(current_index)] = vec[current_index];
                vec[current_index] = tmp;
                current_index = get_parent_node_index(current_index);
            }
        }
        // root 노드를 삭제한다
        void remove_min(){
            if(num_elements == 0){
                std::cout << "no element to be removed\n";
                return;
            }

            int parent_index = 1, child_index = 2, last_node_index = num_elements;

            // root 노드의 값이랑 마지막 노드에 있는 값을 서로 바꾸어준다
            int tmp = vec[1];
            vec[1] = vec[last_node_index];
            vec[last_node_index] = tmp;
            vec.erase(vec.end() - 1);
            --num_elements;

            // 만약 num_elements가 0인경우 heapify를 할 필요가 없다
            if(num_elements == 0) return;

            // heapify를 실행해준다
            while(child_index <= num_elements){
                // 자식들 중에서 더 작은 값을 가진 자식과 교환해줘야한다
                // 왼쪽, 오른쪽 중 더 작은 값을 찾는다
                if(child_index < num_elements && vec[child_index] > vec[child_index + 1])
                    child_index++;
                
                // 만약 부모 노드의 값이 자식 노드의 값 보다 더 작은 경우 반복문을 탈출
                if(vec[parent_index] < vec[child_index]) break;

                // 부모의 노드가 자식의 노드 값 보다 큰 경우 서로 교환
                int tmp = vec[child_index];
                vec[child_index] = vec[parent_index];
                vec[parent_index] = tmp;

                // index update
                parent_index = child_index;
                child_index = get_left_child_node_index(parent_index);
            }
        }
        void peek() const{
            if(num_elements == 0) std::cout << "no element to be peeked\n";
            else std::cout << vec[1] << '\n';
        }
        void show() const{
            if(num_elements == 0){
                std::cout << "no elements to be showed\n";
                return;
            }

            for(int i = 1; i <= num_elements; i++){
                std::cout << vec[i] << ' ';
            }
            std::cout << '\n';
        }
};

#endif // HEAP_HPP