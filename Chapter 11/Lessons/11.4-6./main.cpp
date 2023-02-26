
//usetime1.cpp -- использование второй черновой версии класса Time
#include <iostream>
#include "mytime1.hpp"


int main()
{
    using std::cout;
    using std::endl;
    
    Time planning;
    Time fixing(5,55);
    Time codding(2,40);
    Time total;
    
    cout << "Planning time = ";
    planning.show();
    cout << endl;
    cout << "Codding time = ";
    codding.show();
    cout << endl;
    cout << "Fixing time = ";
    fixing.show();
    cout << endl;
    total = codding + fixing;
    
    // Нотация с операцией
    cout << "codding + fixing = ";
    total.show();
    cout << endl;
    Time morefixing(3,28);
    cout << "more fixing time = ";
    morefixing.show();
    cout << endl;
    total = morefixing.operator+(total);
    
    // Нотация с функцией
    cout << "morefixing.operator+(fixing) = ";
    total.show();
    cout << endl;
    return 0;
}
