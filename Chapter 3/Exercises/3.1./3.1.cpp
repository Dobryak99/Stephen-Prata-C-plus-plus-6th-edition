#include <iostream>
int main()
{
    using namespace std;
    const int inch_per_feet = 12; // константа для перевода в футы
    int inch;
    cout << "Enter your height in inches:___\b\b\b";
    cin >> inch;
    int feet = inch / inch_per_feet; // целое число футов
    int inch2 = inch % inch_per_feet; // остаток от деления для получения дюймов(остатков)
    cout << inch << " inches are " << feet << " feet, " << inch2 << " inches.";
    return 0;
}
