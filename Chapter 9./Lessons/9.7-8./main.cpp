//twofile1.cpp -- переменные с внешним и внутренним связыванием
#include <iostream>
int tom = 3;   // определение внешней переменной
int dick = 30;  //определение внешней переменной

static int harry = 300;   //статическая, внутренне связывание

void remote_access();

int main()
{
    using namespace std;
    cout << "main() reports the folowing adresses:\n";
    cout << &tom << " = &tom, " << &dick << " = &dick, " << & harry << " = &harry.\n";
    remote_access();
    return 0;
}
