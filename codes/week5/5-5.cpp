#include <iostream>
using namespace std;

class Dog{
    private:
        int age;
    public:
        Dog(int age){
            this->age = age;
        }
        int getAge(){
            return age;
        }
        void setAge(int age){
            this->age = age;
        }
};
int main(){
    Dog coco = Dog(3);
    cout << coco.getAge() << '\n';
    return 0;
}