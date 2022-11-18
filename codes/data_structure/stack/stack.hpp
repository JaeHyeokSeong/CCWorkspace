#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>
#include <vector>
using std::vector;
template<class T>
class Stack{
    private:
        int end;
        vector<T> stack;
    public:
        Stack(){
            end = -1;
        }
        void push(const T& a){
            stack.push_back(a);
            end++;
        }
        // stack 마지막 원소 삭제
        void pop(){
            if(end == -1){
                throw std::out_of_range("제거할 원소가 없습니다");
            }else{
                stack.pop_back();
                end--;
            }
        }
        T top(){
            if(end == -1){
                throw std::out_of_range("접근할 원소가 없습니다.");
            } else{
                return stack[end];
            }
        }
        int size(){
            return end + 1;
        }


};
#endif // STACK_HPP