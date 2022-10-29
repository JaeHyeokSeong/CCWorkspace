#include <iostream>
#include "date.hpp"
int main(){
    Date date1("30/10/2022");
    Date date2(29,10,2022);
    date1.view();
    date2.view();
}