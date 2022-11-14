#include <iostream>
#include <algorithm>
#include "product.hpp"

using std::cout;
using std::sort;

bool compare_descendingOrder(Product& p1, Product& p2){
    return p1.getPrice() > p2.getPrice();
}
int main(){
    Product products[5] = {
        Product("iPhone", 999),
        Product("macbook", 3000),
        Product("iPad", 1000),
        Product("apple watch", 800),
        Product("apple pencil", 138)
    };

    sort(products, products + 5, compare_descendingOrder);

    for(int i = 0; i < 5; i++){
        cout << products[i].getName() << ' ' << products[i].getPrice() << '\n';
    }

    return 0;
}