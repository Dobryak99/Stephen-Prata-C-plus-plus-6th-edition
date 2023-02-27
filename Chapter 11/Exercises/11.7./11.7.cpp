#include "11.7.h"

complex::complex()
{
    real = imaginary = 0;
}

complex::complex(int n1, int n2)
{
    real = n1;
    imaginary = n2;
}

complex::~complex()
{

}


complex complex::operator+(const complex & cx)
{
    complex sum;
    sum.real = real + cx.real;
    sum.imaginary = imaginary + cx.imaginary;
    return sum;
}

complex complex::operator-(const complex & cx)
{
    complex sub;
    sub.real = real - cx.real;
    sub.imaginary = imaginary - cx.imaginary;
    return sub;
}

complex complex::operator*(const complex & cx)
{
    complex mult;
    mult.real = (real * cx.real) - (imaginary * cx.imaginary);
    mult.imaginary = (real * cx.imaginary) + (cx.real * imaginary);
    return mult;
}

complex operator*(double number, const complex & cx)
{
    complex mult;
    mult.real = number * cx.real;
    mult.imaginary = number * cx.imaginary;
    return mult;
}

complex complex::operator*(double number)
{
    return number * (*this);
}

complex operator~(const complex & cx)
{
    complex conjugate;
    conjugate.real =cx.real;
    conjugate.imaginary = cx.imaginary;
    return conjugate;
}

std::ostream & operator<<(std::ostream & os, const complex & cx)
{
    os << "(" << cx.real << ", " << cx.imaginary << "i)";
    return os;
}
std::istream & operator>>(std::istream & is, complex & cx)
{
    std::cout << "real: ";
    is >> cx.real;
    if(cx.real)
    {
        std::cout << "imaginary: ";
        is >> cx.imaginary;
    }
    return is;
}
