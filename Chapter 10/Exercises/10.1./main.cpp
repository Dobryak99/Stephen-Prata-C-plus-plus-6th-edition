#include <iostream>
#include "bankacc.h"
#include "bankacc.cpp"

int main()
{
    using std::cout;
    Account first("Sberbank", "40817810123456789098", 3023.45);
    first.show();
    cout << "Now we add some money.\n";
    first.add(330.23);
    cout << "Now we transfer some money.\n";
    first.transfer(1234.98);
    cout << "Let's try to transfer more.\n";
    first.transfer(3000);
    cout << "Bye!\n";


    first.Del();
    return 0;
}
