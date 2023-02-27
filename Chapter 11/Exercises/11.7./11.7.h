#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include <iostream>
class complex
{
    private:
        int real;
        int imaginary;
    public:
        complex();
        complex(int n1, int n2 = 0);
        ~complex();
        complex operator+(const complex & cx);
        complex operator-(const complex & cx);
        complex operator*(const complex & cx);
        complex operator*(double number);
        friend complex operator~(const complex & cx);
        friend complex operator*(double number, const complex & cx);
        friend std::ostream & operator<<(std::ostream & os, const complex & cx);
        friend std::istream & operator>>(std::istream & is, complex & cx);
};

#endif
