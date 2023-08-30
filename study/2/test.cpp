// 操作符重载
#include <iostream>
using namespace std;

class Complex
{
public:
    double real;
    double image;
    Complex(double real, double image):
        real(real), image(image)
        {}
    
    Complex operator+(Complex& other){
        return Complex(this->real + other.real, this->image + other.image);
    }

    Complex operator*(Complex& other){
        double a = this->real;
        double b = this->image;
        double c = other.real;
        double d = other.image;
        return Complex(a*c -b*d, b*c + a*d);
    }

};

int main(int argc, char const *argv[])
{
    /* code */
    Complex c1(1.0f, 2.0f);
    Complex c2(2.0f, 3.0f);
    Complex c3 = c1 * c2;
    // cout << "c1 = " << c1 << endl;
    // cout << "c2 = " << c2 << endl;
    cout << "c3 = " << c3.real << ", " << c3.image << endl;
    return 0;
}
