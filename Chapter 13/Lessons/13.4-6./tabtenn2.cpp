#include "tabtenn2.hpp"
#include <iostream>


TableTennisPlayer::TableTennisPlayer(const string & fn, const string & ln, bool hs) : firstname(fn), lastname(ln), hasTable(hs)
{
    
}

void TableTennisPlayer::Name() const
{
    std::cout << lastname << ", " << firstname;
}

RatedPlayer::RatedPlayer(unsigned int r, const string & fn, const string & ln, bool ht) : TableTennisPlayer(fn, ln, ht)
{
    rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp) : TableTennisPlayer(tp), rating(r)
{
}
