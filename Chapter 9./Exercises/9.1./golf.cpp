#include <iostream>
#include <cstring>
#include "golf.h"

void setgolf(golf & g, const char * name, int hc)
{
    strcpy(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf & g)
{
    int name_valid = 0;
    std::cout << "Enter the name of the player: \n";
    std::cin.get(g.fullname,Len);
    if(strlen(g.fullname) > 0)
    {
        name_valid = 1;

        std::cout << "Enter the player's handicap: \n";
        std::cin >> g.handicap;
        std::cin.get();
    }else if(g.fullname[0] != '\n'){
        std::cout << "Bad input.\n";
    }
    return name_valid;
}

void handicap(golf & g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf & g)
{
    std::cout << "The name: " << g.fullname  << ".\n";
    std::cout << g.fullname << " handicap = " << g.handicap << std::endl;
}


