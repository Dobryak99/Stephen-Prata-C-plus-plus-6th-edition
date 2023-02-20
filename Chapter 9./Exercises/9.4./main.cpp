#include <iostream>
#include "sales.cpp"

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    SALES::Sales shop1, shop2;
    double sales[4] = {4.34, 2.67, 34.12, 12.56};
    cout << "=================================\n";
    SALES::setSales(shop1, sales, 4);
    SALES::setSales(shop2);
    cout << "Show first function: ";
    SALES::showSales(shop1);
    cout << "Show second function: ";
    SALES::showSales(shop2);
    cout << "=================================\n";
    return 0;
}
