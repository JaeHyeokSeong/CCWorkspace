#include <iostream>
#include <algorithm>
#include "queue.hpp"
using std::cout;
using std::sort;
using std::cin;

int main(){
    Queue<int> q;
    int i = 0;
    int value;
    do{
        cout << "\n1 - push, 2 - pop, 3 - front, 4 - back, 5 - size, 6 - empty, 7 - exit\n";
        cin >> i;
        if(i == 1){
            cout << "enter a value : ";
            cin >> value;
            q.push(value);
        } 
        else if(i == 2){
            try{
                q.pop();
            } catch(std::out_of_range e){
                cout << e.what() << '\n';
            }
        }
        else if(i == 3){
            try{
                value = q.front();
                cout << "front value : " << value << '\n';
            } catch(std::out_of_range e){
                cout << e.what() << '\n';
            }
        }
        else if(i == 4){
            try{
                value = q.back();
                cout << "back value : " << value << '\n';
            } catch(std::out_of_range e){
                cout << e.what() << '\n';
            }
        }
        else if(i == 5){
            value = q.size();
            cout << "size : " << value << '\n';
        }
        else if(i == 6){
            value = q.empty();
            cout << "empty : " << value << '\n';
        }
        else if(i == 7){
            cout << "program finished\n";
        }
        else {
            cout << "invalid input\n";
        }
    }while(i != 7);
    return 0;
}