#include <iostream>
#include <cstring>
#include "ex10_2.h"


Person::Person(const std::string & ln, const char * fn)
{
    lname = ln;
    strcpy(fname, fn);
}

void Person::show() const
{
    std::cout << "The output #1: ";
    std::cout << fname << " " << lname << "\n";
}

void Person::Formalshow() const
{
    std::cout << "The output #2: ";
    std::cout << lname << " " << fname << "\n";
}

Person::~Person()
{

}
