#include <iostream>
#include <ctime>
using std::cout;

int generate_waitingNumber(){
    struct tm curr_tm;
    time_t curr_time = time(nullptr);
    localtime_r(&curr_time, &curr_tm);

    static int waitingNumber = 1;
    
    return 1;
}
int main(){
    generate_waitingNumber();
    return 0;
}