#include <iostream>
#include "10.7.h"
//#include "10.7.cpp"

int main()
{
    Plorg prog1;
    prog1.show();
    std::cout << "\n";
    Plorg prog2("New Plorg", 132);
    prog2.show();
    prog2.new_CI(342);
    prog2.show();
    std::cout << "\n";
    Plorg prog3("Mamacita");
    prog3.show();
    return 0;
}
