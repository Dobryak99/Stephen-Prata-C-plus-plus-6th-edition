//error1.cpp -- использвоание функции abort()
#include <iostream>
#include <cstdlib>

double hmean(double a, double b);
int main()
{
    double x, y, z;
    std::cout << "Enter two numbers: ";
    while(std::cin >> x >> y)
    {
        z = hmean(x,y);
        std::cout << "Harmonic mean of " << x  << " and " << y << " is " << z << std::endl;
        std::cout << "Enter next two numbers(q to quit): ";
    }
    std::cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b)
{
    if(a == -b)
    {
        std::cout << "Untenable arguments to hmean()\n";
        std::abort();
    }
    return 2.0 * a * b / (a + b);
}
