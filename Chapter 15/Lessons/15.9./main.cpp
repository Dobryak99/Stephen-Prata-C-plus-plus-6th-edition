//error3.cpp -- использвоание функции abort()
#include <iostream>

double hmean(double a, double);
int main()
{
    double x, y, z;
    std::cout << "Enter two numbers: ";
    while(std::cin >> x >> y)
    {
        try{
            z = hmean(x,y);
        }
        catch(const char * s)
        {
            std::cout << s << std::endl;
            std::cout << "Enter a new pair of numbers: ";
            continue;
        }
        std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << std::endl;
        std::cout << "Enter next two numbers(q to quit): ";
    }
    std::cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b)
{
    if(a == -b)
    {
        throw "Bad hmean() arguments: a = -b not allowed";
    }
    return (2.0 * a * b) / (a + b);
}
