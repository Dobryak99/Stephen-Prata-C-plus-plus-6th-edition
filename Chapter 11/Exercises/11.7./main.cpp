#include <iostream>
#include "11.7.h"
//#include "11.7.cpp"
using namespace std;
int main()
{
    complex a(3.0, 4.0);  // Инициализация значением (3, 4i)
    complex c;
    cout << "Enter a complex number (q to quit):\n";
    while(cin >> c)
    {
        cout << "c is " << c << '\n';
        cout << "complex conjugate is " << ~c << '\n';  //значение сопряженного числа
        cout << "a is " << a << '\n';
        cout << "a + c is " << a + c << '\n';
        cout << "a - c is " << a - c << '\n';
        cout << "a * c is " << a * c << '\n';
        cout << "2 * c is " << 2 * c << '\n';
        cout << "c * 2 is " << c * 2 << '\n';           //дополнительная проверка
        cout << "Enter a complex number (q to quit):\n";
    }
    cout << "Done!\n";
    return 0;
}
