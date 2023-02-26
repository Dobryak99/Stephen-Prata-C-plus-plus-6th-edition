//musetime.cpp -- использование первой черновой версии класса Time
#include <iostream>
#include "mytime0.hpp"

int main()
{
    using std::cout;
    using std::endl;
    
    Time planning;
    Time codding(2,40);
    Time fixing(5,55);
    Time total;
    cout << "Planning time = ";   //  время на планирование
    planning.show();
    cout << endl;
    cout << "Coding time = ";  // время на кодирование
    codding.show();
    cout << endl;
    cout << "Fixing time = ";  // время на исправление
    fixing.show();
    cout << endl;
    total = codding.Sum(fixing);
    cout << "codding.sum(fixing) = ";
    total.show();
    cout << endl;
    return 0;
}
