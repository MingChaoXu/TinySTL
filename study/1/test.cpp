#include <iostream>
using namespace std;

template<typename T>
void MySwap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

int main(int argc, char const *argv[])
{
    /* code */
    int a = 10;
    int b = 20;
    double aa = 10.1;
    double bb = 20.2;
    MySwap(a, b);
    MySwap(aa, bb);
    cout << "a = " << a << ";b = " << b << endl;
    cout << "aa = " << aa << ";bb = " << bb << endl;
    return 0;
}
