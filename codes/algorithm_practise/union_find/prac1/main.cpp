#include <iostream>
#include "union_find.hpp"

int main(){
    int parents[11];
    for(int i = 1; i < 11; i++){
        parents[i] = i;
    } 

    my_algorithm::unionParent(parents, 1, 2);
    my_algorithm::unionParent(parents, 2, 3);
    my_algorithm::unionParent(parents, 3, 4);
    my_algorithm::unionParent(parents, 5, 6);
    my_algorithm::unionParent(parents, 6, 7);
    my_algorithm::unionParent(parents, 7, 8);

    std::cout << "1 과 5 의 연관성 = " << my_algorithm::unionFind(parents, 1, 5) << '\n';

    my_algorithm::unionParent(parents, 1, 5);
    std::cout << "1 과 5 의 연관성 = " << my_algorithm::unionFind(parents, 1, 5) << '\n';
    return 0;
}