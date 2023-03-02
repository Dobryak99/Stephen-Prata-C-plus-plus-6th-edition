#include "tabtenn.hpp"
#include <iostream>


TableTennisPlayer::TableTennisPlayer(const string & fn, const string & ln, bool hs) : firstname(fn), lastname(ln), hasTable(hs)
{
    
}

void TableTennisPlayer::Name() const
{
    std::cout << lastname << ", " << firstname;
}
