#include <iostream>

class MyComplex {
  public:
    MyComplex(double real = 0, double imag = 0) : real_(real), imag_(imag) {}
    MyComplex operator+(const MyComplex& other) const {
        return MyComplex(real_ + other.real_, imag_ + other.imag_);
    }
    friend std::ostream& operator<<(std::ostream& os, const MyComplex& complex);
    double real_;
    double imag_;
};

std::ostream& operator<<(std::ostream& os, const MyComplex& complex)
{
    os << "(" << complex.real_ << ", " << complex.imag_ << ")";
    return os;
}

int main() {
    MyComplex a(1, 2);
    MyComplex b(3, 4);
    MyComplex c = a + b;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c = a + b: " << c << std::endl;
    return 0;
}
