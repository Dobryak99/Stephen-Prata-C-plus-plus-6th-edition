// callable.cpp -- вызываемые типы и шаблоны
#include "somedefs.h"
#include <iostream>

double dub(double x) {return 2.0 * x;}
double square(double x) {return x * x;}

int main()
{
    using std::cout;
    using std::endl;
    
    double y = 1.21;
    
    cout << "Function pointer dub:\n";              //указатель на функцию dub
    cout << " " << use_f(y,dub) << endl;
    cout << "Function pointer square:\n";           //указатель на функцию square
    cout << " " << use_f(y, square) << endl;
    cout << "Finction object Fp:\n";                // функциональный объект Fp
    cout << " " << use_f(y, Fp(5.0)) << endl;
    cout << "Finction object Fq:\n";                // функциональный объект Fq
    cout << " " << use_f(y,Fq(5.0)) << endl;
    cout << "Lambda expression 1:'n";
    cout << " " << use_f(y, [](double x) {return x * x;}) << endl;
    cout << "Lambda expression 2:'n";
    cout << " " << use_f(y, [](double x) {return x + x/2.0;}) << endl;
    return 0;
}
