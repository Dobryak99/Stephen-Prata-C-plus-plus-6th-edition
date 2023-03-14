//precise.cpp -- установка точности
#include <iostream>

int main()
{
    using std::cout;
    float price1 = 20.40;
    float price2 = 1.9 + 8.0 /9.0;
    
    cout << "\"Furry Friends\" is $" << price1 << "!\n";
    cout << "\"Fiery Friends\" is $" << price2 << "!\n";
    
    cout.precision(2);
    cout << "\"Furry Friends\" is $" << price1 << "!\n";
    cout << "\"Fiery Friends\" is $" << price2 << "!\n";
    return 0;
}
