#include "wine2.h"

Wine::Wine(const char * l, int y, const int yr[], const int bt[]) : std::string(l), years(y), PairArray(ArrayInt(y),ArrayInt(y))
{
    for(int i = 0; i < years; i++)
    {
        PairArray::first[i] = yr[i];
        PairArray::second[i] = bt[i];
    }
}

Wine::Wine(const char * l, int y) : std::string(l), years(y), PairArray(ArrayInt(y),ArrayInt(y))
{
    
}

void Wine::Show() const
{
    std::cout << "Wine: " << (const std::string &) *this << std::endl;
    std::cout << "\tYear" << "\tBottles" << std::endl;
    for(int i = 0; i < years; i++)
    {
        std::cout << "\t" << PairArray::first[i] << "\t" << PairArray::second[i] << std::endl;
    }
}

void Wine::GetBottles()
{
    std::cout << "Enter " << (const std::string &) *this << " data for " << years << " year(s):\n";
    for(int i = 0; i < years; i++)
    {
        std::cout << "Enter year: ";
        std::cin >> PairArray::first[i];
        std::cout << "Enter bottles for that year: ";
        std::cin >> PairArray::second[i];        
    }
}

const std::string & Wine::Label() const
{
    return (const std::string &) *this;
}

int Wine::sum()
{
    int total = 0;
    for(int i = 0; i < years; i++)
    {
        total += PairArray::second[i];
    }
    return total;
}
