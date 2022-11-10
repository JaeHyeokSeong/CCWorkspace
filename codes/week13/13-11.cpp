#include <iostream>
using std::cout;

template<class T1, class T2>
class A{
    public:
        T1 a;
        T2 b;
        A(T1 a, T2 b){
            this->a = a;
            this->b = b;
        }
};
int main(){
    A<char, const char*> a('a', "hello world");
    cout << a.a << "\t" << a.b << '\n';    

    A<int, int> b(10,20);
    cout << b.a << '\t' << b.b << '\n';
    return 0;
}