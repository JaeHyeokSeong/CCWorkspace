#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <vector>
using std::vector;
template<class T>
class Queue{
    private:
        int start, end;
        vector<T> q;
    public:
        Queue(){
            start = 0;
            end = -1;
        }
        void push(const T value){
            q.push_back(value);
            end++;
        }
        void pop(){
            if(start <= end){
                q.erase(q.begin());
                end--;
            } else{
                throw std::out_of_range("pop할 원소가 없습니다.");
            }
        }
        T front() const{
            if(start <= end){
                return q[start];
            } else{
                throw std::out_of_range("front할 원소가 없습니다.");
            }
        }
        T back() const{
            if(start <= end){
                return q[end];
            } else{
                throw std::out_of_range("back할 원소가 없습니다.");
            }
        }
        int size() const{
            return end-start+1;
        }
        int empty() const{
            if(end == -1){
                return 1;
            }else{
                return 0;
            }
        }
        int operator [](const int index) const{
            return q[index];
        }
};
#endif // QUEUE_HPP