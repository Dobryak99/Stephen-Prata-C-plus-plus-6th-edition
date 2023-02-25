#include <iostream>
#include "ex10_4.h"
//#include "ex10_4.cpp"

int main()
{
    double arr1[] = {123.33, 324.56, 345.66, 125.87};
    SALES::Sales shop1(arr1, SALES::QUARTERS);
    shop1.showSales();
    std::cout << "\n";
    SALES::Sales shop2;
    shop2.setSales();
    shop2.showSales();
    return 0;
}
