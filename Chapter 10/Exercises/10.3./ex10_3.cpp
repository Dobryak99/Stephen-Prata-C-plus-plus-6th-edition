#include <iostream>
#include "ex10_3.h"
#include <cstring>

Golf::Golf()
{
    strcpy(fullname, "NoName");
    handicap = 0;
}

Golf::Golf(const char * fn, int hc)
{
    strcpy(fullname, fn);
    handicap = hc;
}

Golf::~Golf()
{

}

int Golf::setGolf()
{
    int name_valid = 0;
    std::cout << "Enter name of the player: ";
    std::cin.get(fullname, Len);
    if(strlen(fullname) > 0)
    {
        name_valid = 1;
        std::cout<< "Enter player's handicap: ";
        (std::cin >> handicap).get();
        Golf temp(fullname, handicap);
        *this = temp;
    }
    return name_valid;
}

void Golf::showGolf() const
{
    std::cout << fullname << "\n";
    std::cout << "Handicap: " << handicap << "\n";
}

void Golf::Handicap(int n)
{
    handicap = n;
}
