//support.cpp -- использование внешних переменных
//компилировать вместе с external.cpp
#include <iostream>
extern double warming; // использование переменной из другого файла
void update(double dt);

void local();

using std::cout;
void update(double dt)
{
    extern double warming;  //необязятаельное повторное объявление
    warming += dt;
    cout << "Updating global warming to " << warming << " degrees.\n";
}

void local()
{
    double warming = 0.8;
    cout << "Local warming = " << warming << " degrees.\n";
    cout << "But global warming = " << ::warming << " degrees.\n";  //достпу к глобальное переменной с помощью операции разрешения контекста
}
