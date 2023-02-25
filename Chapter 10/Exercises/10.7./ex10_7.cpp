#include <iostream>
#include <cstring>
#include "10.7.h"

Plorg::Plorg()
{
    strcpy(fullname, "Plorga");
    CI = 0;
}

Plorg::Plorg(const char * fn, int ci)
{
    strcpy(fullname, fn);
    CI = ci;
}

void Plorg::new_CI(int n)
{
    CI = n;
}

void Plorg::show() const
{
    std::cout << "The name: " << fullname << "\n";
    std::cout << "CI: " << CI << "\n";
}

Plorg::~Plorg()
{
    
}
