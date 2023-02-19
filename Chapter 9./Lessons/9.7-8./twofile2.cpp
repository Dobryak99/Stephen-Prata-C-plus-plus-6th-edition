// twofile2.cpp -- переменные с внутренним и внешним связыванием
#include <iostream>

extern int tom;
static int dick = 10;  //переопределяет внешнюю переменную dick
int harry = 200;  //определение внешней переменной

void remote_access()
{
    using namespace std;
    cout << "remote_access() reports the folowing adresses:\n";
    cout << &tom << " = &tom, " << &dick << " = &dick, " << & harry << " = &harry.\n";
}
