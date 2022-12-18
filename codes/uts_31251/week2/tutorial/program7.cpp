// program 7 - (singly) linked list
#include <iostream>
template <class T>
class Node{
    public: 
        T data;
        Node<T>* next;
        Node<T>* privous;
        Node(){
            next = NULL;
            privous = NULL;
        }
};
template <class T>
class MyIterator{
    private:
        Node<T>* current;
    public:
        MyIterator(Node<T>* current = NULL){
            this->current = current;
        }
        Node<T>* get_current() const{
            return current;
        }
        MyIterator& operator++(){
            current = current->next;
            return *this;
        }
        T& operator*(){
            return current->data;
        } 
        bool operator!=(const MyIterator& ref){
            return current != ref.current;
        }
};
template <class T>
class Single_Linkded_List{
    private:
        Node<T>* head;
        Node<T>* tail;
        int count;
    public:
        Single_Linkded_List(){
            head = NULL;
            tail = NULL;
            count = 0;
        }
        ~Single_Linkded_List(){
            while(head != NULL){
                Node<T>* tmp = head;
                head = head->next;
                delete tmp;
            }
        }
        typedef MyIterator<T> iterator;
        iterator begin(){
            return iterator(head);
        }
        iterator end(){
            return iterator(NULL);
        }
        void push_front(const T data){
            count++;
            Node<T>* tmp = new Node<T>;
            tmp->data = data;
            tmp->next = head;
            // 아직 어떠한 원소도 리스트안에 추가되어지지 않은 경우.
            if(head == NULL && tail == NULL){
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
            tmp->data = data;
            tmp->privous = tail;
            // 아직 어떠한 원소도 리스트안에 추가되어지지 않은 경우.
            if(head == NULL && tail == NULL){
                head = tmp;
                tail = tmp;
                return;
            }
            tail->next = tmp;
            tail = tmp;
        }
        void insert(iterator& iter, const T element){
            Node<T>* new_node = new Node<T>;
            new_node->data = element;
            Node<T>* iter_node = iter.get_current();
            Node<T>* privous_node = iter_node->privous;
            // node가 1개만 있었던 경우에서 삽입을 시행하면 push_front()을 사용해주면 된다
            if(privous_node == NULL){
                push_front(element);
                return;
            }
            privous_node->next = new_node;
            new_node->next = iter_node;
            iter_node->privous = new_node;
            new_node->privous = privous_node;
        }
        void pop_front(){
            if(head == NULL && tail == NULL)
                return;
            count--;
            Node<T>* tmp = head->next;
            delete head;
            head = tmp;
            if(head == NULL){
                tail = NULL;
            } else{
                head->privous = NULL;
            }
        }
        void pop_back(){
            if(tail == NULL){
                return;
            }
            count--;
            Node<T>* tmp = tail->privous;
            delete tail;
            tail = tmp;
            if(tail == NULL){
                head = NULL;
            } else{
                tail->next = NULL;
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
            while(tmp != NULL){
                std::cout << tmp->data << ' ';
                tmp = tmp->next;
            }
            std::cout << '\n';
        }
};
int main(){
    Single_Linkded_List<int> sll;
    for(int i = 0; i < 5; i++){
        sll.push_back(i);
    }
    for(Single_Linkded_List<int>::iterator iter = sll.begin(); iter != sll.end(); ++iter){
        std::cout << *iter << '\n';
    }
    Single_Linkded_List<int>::iterator iter = sll.begin();
    ++iter;
    ++iter;
    sll.insert(iter, 100);
    std::cout << "after insert method\n";
    for(Single_Linkded_List<int>::iterator iter = sll.begin(); iter != sll.end(); ++iter){
        std::cout << *iter << '\n';
    }
    sll.push_back(200);
    for(Single_Linkded_List<int>::iterator iter = sll.begin(); iter != sll.end(); ++iter){
        std::cout << *iter << '\n';
    }
    // leaks command 위해서 무한루프 적음 
    // ./program7 & leaks program7
    while(1){

    }
    return 0;
}