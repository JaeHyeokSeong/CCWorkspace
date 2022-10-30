#include <iostream>
#include "point.hpp"
using std::cout;

int main(){
    Point point1(1,2), point2(1,2), point3;
    // point3 = point1 * point2;
    // point3.view();
    // if(point1 == point2){
    //     cout << "equal\n";
    // } else{
    //     cout << "inequal\n";
    // }

    if(point1!=point2){
        cout << "두 좌표는 다릅니다.\n";
        return 0; 
    }
    cout << "두 좌표는 같습니다.\n";
    return 0;
}