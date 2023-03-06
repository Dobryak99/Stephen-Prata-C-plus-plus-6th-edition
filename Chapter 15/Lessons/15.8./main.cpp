//error1.cpp -- использвоание функции abort()
#include <iostream>
#include <cfloat>           //для DBL_MAX

bool hmean(double a, double, double * ans);
int main()
{
    double x, y, z;
    std::cout << "Enter two numbers: ";
    while(std::cin >> x >> y)
    {
        if(hmean(x,y, &z))
        {
            std::cout << "Harmonic mean of " << x  << " and " << y << " is " << z << std::endl;
        }else{
            std::cout << "One value should not be the negative of the other - try again.\n";
        }
        std::cout << "Enter next two numbers(q to quit): ";
    }
    std::cout << "Bye!\n";
    return 0;
}

bool hmean(double a, double b, double * ans)
{
    if(a == -b)
    {
        *ans = DBL_MAX;
        return false;
    }
    *ans = (2.0 * a * b) / (a + b);
    return true;
}
