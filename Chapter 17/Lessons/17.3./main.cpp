//manip.cpp -- использование манипуляторов формата
#include <iostream>

int main()
{
    using namespace std;
    
    //вывод приглашения к вводу числа
    cout << "Enter an integer: ";
    int n;
    cin >> n;
    cout << "n   n*n\n";
    cout << n << "   " << n * n << " (decimal)\n";
    
    //установка шестандцатеричного режима вывода
    cout << hex;
    cout << n << "   " << n * n << " (hexadecimal)\n";
    
    //установка восьмерчного режима
    cout << oct << n <<   " " << n * n << " (octal)\n";
    
    //альтернативный способ вызова манипулятора
    dec(cout);
    cout << n << "   " << n*n << " (decimal)\n";
    return 0;
}
