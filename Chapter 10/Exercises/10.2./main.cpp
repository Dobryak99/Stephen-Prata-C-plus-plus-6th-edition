#include <iostream>
#include "ex10_2.h"
#include "ex10_2.cpp"

int main()
{
    Person one; //  используется конструктор по умолчанию
    Person two ("Smythecraft"); //  #2 с одним аргументом по умолчанию
    Person three ("Dimwiddy", " Sam");   //  #2 без аргументов по умолчанию
    one.show();
    std::cout << "\n";
    one.Formalshow();
    std::cout << "\n";
    two.show();
    std::cout << "\n";
    two.Formalshow();
    std::cout << "\n";
    three.show();
    std::cout << "\n";
    three.Formalshow();
    std::cout << "\n";
    return 0;
}
