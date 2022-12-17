#include <iostream>
#include <list>
using std::list;

int main(){
    list<int> li;
    list<int>::iterator it;

    for(int i = 0; i < 10; i++){
        li.push_back(i);
    }    
    for(it = li.begin(); it != li.end(); it++){
        printf("%d ", *it);
    }
    printf("\n");
    it = li.begin();
    it++;
    li.insert(it, 100);
    for(int x : li){
        printf("%d ", x);
    }
    return 0;
}