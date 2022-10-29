#include <iostream>
#include <sstream>
using std::cout;
using std::string;
using std::stoi;

class Date{
    private:
        int day, month, year;
    public:
        Date(){
            day=0; month = 0; year = 0;
        }
        Date(const char* date){
            std::istringstream iss(date);
            char separator = '/';
            int i = 0;
            int results[3];
            string str_buf;
            while(getline(iss, str_buf, separator)){
                results[i++] = stoi(str_buf);
            }
            day = results[0];
            month = results[1];
            year = results[2];
        }
        Date(int day, int month, int year){
            this->day = day;
            this->month = month;
            this->year = year;
        }
        void view() const{
            cout << "day: " << day << ", month: " << month << ", year: " << year << '\n';
        }
};