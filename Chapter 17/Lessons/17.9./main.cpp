//setf2.cpp -- использование setf() с двумя аргументами для управления форматирвоания
#include <iostream>
#include <cmath>

int main()
{
    using namespace std;
    
    //использовать выравнивание влево,  показать знак плюс,
    //показать завершающие нули с точностью, равной 3
    cout.setf(ios_base::left, ios_base::adjustfield);           //выравнивание влево
    cout.setf(ios_base::showpos);                               //плюс перед числом
    cout.setf(ios_base::showpoint);                             //отображение завершающей десятичной точки
    cout.precision(3);
    
    // использование экспоненциальную запись и сохранить старые установки формата
    ios_base::fmtflags old = cout.setf(ios_base::scientific, ios_base::floatfield);
    
    cout << "Left justification:\n";
    long n;
    for(n = 1; n <= 41; n+=10)
    {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double (n)) << "|\n";
    }
    
    //переключится на внутреннее выравнивание
    cout.setf(ios_base::internal, ios_base::adjustfield);
    
    //восстановить стиль отображения значений с плавающей точкой, заданный по умолчанию
    cout.setf(old, ios_base::floatfield);
    
    cout << "Internal Justification:\n";
    for(n = 1; n <= 41; n+=10)
    {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double (n)) << "|\n";
    }
    
    //использование выравнивания по правому краю и форму записи с фиксированной точкой
    cout.setf(ios_base::right, ios_base::adjustfield);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << "Right justification:\n";
    for(n = 1; n <= 41; n+=10)
    {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double (n)) << "|\n";
    }
    return 0;
}
