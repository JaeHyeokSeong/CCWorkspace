// Program 4 - what does resize() do?
#include <iostream>
#include <list>

int main(){
    std::list<int> lst;
    lst.push_back(4);
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(5);
    lst.resize(10, 10); // make list size to 10 and and number 10 into empty spaces 
    for(std::list<int>::iterator it = lst.begin(); it != lst.end(); it++){
        std::cout << *it << '\n';
    }
    return 0;
}