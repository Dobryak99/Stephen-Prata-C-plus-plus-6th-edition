// wrapped.cpp -- вызываемые типы и шаблоны
#include "somedefs.h"
#include <iostream>
#include <functional>

double dub(double x) {return 2.0 * x;}
double square(double x) {return x * x;}

int main()
{
    using std::cout;
    using std::endl;
    
    double y = 1.21;
    
    std::function<double(double)> ef1 = dub;
    std::function<double(double)> ef2 = square;
    std::function<double(double)> ef3 = Fp(10.0);
    std::function<double(double)> ef4 = Fq(10.0);
    std::function<double(double)> ef5 = [](double u){return u * u;};
    std::function<double(double)> ef6 = [](double u){return u + u/2.0;};
    cout << "Function pointer dub:\n";              //указатель на функцию dub
    cout << " " << use_f(y,ef1) << endl;
    cout << "Function pointer square:\n";           //указатель на функцию square
    cout << " " << use_f(y, ef2) << endl;
    cout << "Finction object Fp:\n";                // функциональный объект Fp
    cout << " " << use_f(y, ef3) << endl;
    cout << "Finction object Fq:\n";                // функциональный объект Fq
    cout << " " << use_f(y,ef4) << endl;
    cout << "Lambda expression 1:\n";
    cout << " " << use_f(y, ef5) << endl;
    cout << "Lambda expression 2:\n";
    cout << " " << use_f(y, ef6) << endl;
    return 0;
}
