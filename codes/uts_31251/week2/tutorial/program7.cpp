// program 7 - (singly) linked list
#include <iostream>
template <class T>
class Node{
    public: 
        T data;
        Node<T>* next = nullptr;
        Node<T>* privous = nullptr;
};
template <class T>
class Single_Linkded_List{
    private:
        Node<T>* head = nullptr;
        Node<T>* tail = nullptr;
        int count = 0;
    public:
        Single_Linkded_List(){}
        ~Single_Linkded_List(){
            while(head != nullptr){
                Node<T>* tmp = head;
                head = head->next;
                std::cout << "delete: " << tmp << '\n';
                delete tmp;
            }
        }
        void push_front(const T data){
            count++;
            Node<T>* tmp = new Node<T>;
            std::cout << "push front: " << tmp << '\n';
            tmp->data = data;
            tmp->next = head;
            // 아직 어떠한 원소도 리스트안에 추가되어지지 않은 경우.
            if(head == nullptr && tail == nullptr){
                head = tmp;
                tail = tmp;
                return;
            }
            head->privous = tmp;
            head = tmp;
        }
        void push_back(const T data){
            count++;
            Node<T>* tmp = new Node<T>;
            std::cout << "push back: " << tmp << '\n';
            tmp->data = data;
            tmp->privous = tail;
            // 아직 어떠한 원소도 리스트안에 추가되어지지 않은 경우.
            if(head == nullptr && tail == nullptr){
                head = tmp;
                tail = tmp;
                return;
            }
            tail->next = tmp;
            tail = tmp;
        }
        void pop_front(){
            if(head == nullptr && tail == nullptr)
                return;
            count--;
            Node<T>* tmp = head->next;
            std::cout << "pop front: " << head << '\n';
            delete head;
            head = tmp;
            if(head == nullptr){
                tail = nullptr;
            } else{
                head->privous = nullptr;
            }
        }
        void pop_back(){
            if(tail == nullptr){
                return;
            }
            count--;
            Node<T>* tmp = tail->privous;
            std::cout << "pop back: " << tail << '\n';
            delete tail;
            tail = tmp;
            if(tail == nullptr){
                head = nullptr;
            } else{
                tail->next = nullptr;
            }
        }
        T front(){
            return head->data;
        }
        T back(){
            return tail->data;
        }
        int size() const {
            return count;
        }
        bool empty(){
            if(count == 0) 
                return true;
            return false;
        }
        void display(){
            Node<T>* tmp = head;
            while(tmp != nullptr){
                std::cout << tmp->data << ' ';
                tmp = tmp->next;
            }
            std::cout << '\n';
        }
};
int main(){
    Single_Linkded_List<int> sll;
    sll.push_back(1);
    sll.display(); // 1
    std::cout << sll.size() << '\n'; // 1
    sll.pop_front();
    sll.push_back(10);
    sll.push_back(20);
    sll.push_back(30);
    std::cout << sll.size() << '\n'; // 3
    std::cout << sll.front() << '\n'; // 10
    sll.display(); // 10 20 30
    sll.pop_back(); 
    sll.display(); // 10 20
    std::cout << sll.back() << '\n'; // 20
    return 0;
}