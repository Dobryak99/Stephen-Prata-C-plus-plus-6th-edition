// external.cpp -- внешние переменные
//компилировать вместе с support.cpp
#include <iostream>

using namespace std;

double warming = 0.3;  //внешняя переменная

void update(double dt);

void local();

int main()
{
    cout << "Global warming is " << warming << " degrees.\n";
    update(0.1);
    cout << "Global warming is " << warming << " degrees.\n";
    local();
    cout << "Global warming is " << warming << " degrees.\n";
    return 0;
}
