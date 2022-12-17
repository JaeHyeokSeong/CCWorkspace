// program 7 - (singly) linked list
#include <iostream>
template <class T>
class Node{
    public: 
        T data;
        Node<T>* next = nullptr;
};
template <class T>
class Single_Linkded_List{
    private:
        Node<T>* head = nullptr;
    public:
        Single_Linkded_List(){}
        ~Single_Linkded_List(){
            while(head != nullptr){
                Node<T>* tmp = head;
                head = head->next;
                delete tmp;
            }
        }
        void push_front(T data){
            Node<T>* tmp = new Node<T>;
            tmp->data = data;
            tmp->next = head;
            head = tmp;
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
    for(int i = 0; i < 3; i++){
        sll.push_front(i);
    }
    sll.display(); // 2 1 0
    return 0;
}