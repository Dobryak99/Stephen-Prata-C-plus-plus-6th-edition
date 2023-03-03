#include "CD.h"
#include <cstring>
#include <iostream>



//Методы базового класса
Cd::Cd(const char * s1,const char * s2, int n, double x)
{
    std::strncpy(performance, s1,50 - 1);
    performance[50-1] = '\0';
    std::strncpy(label, s2,20 - 1);
    label[20 - 1] = '\0';
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d)
{
    std::strcpy(performance, d.performance);
    std::strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd()
{
    performance[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0.0;
}

Cd::~Cd()
{

}

void Cd::Report() const
{
    std::cout << "Name of the band: " << performance << std::endl;
    std::cout << "Label: " << label << std:: endl;
    std::cout << "Selections: " << selections << std::endl;
    std::cout << "Playtime: " << playtime << std::endl;
}

Cd & Cd::operator=(const Cd & d)
{
    if(this == &d)
    {
        return *this;
    }
    std::strcpy(performance, d.performance);
    std::strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

//Методы производного класса
Classic::Classic(const char * t,const char * s1,const char * s2, int n, double x) : Cd(s1,s2,n,x)
{
    std::strncpy(track, t,100 - 1);
    track[100-1] = '\0';
}

Classic:: Classic(const char * t, const Cd & d) : Cd(d)
{
    std::strncpy(track, t, 100-1);
    track[100-1] = '\0';
}
Classic::Classic() : Cd()
{
    track[0] = '\0';
}

void Classic::Report() const
{
    Cd::Report();
    std::cout << "Name of the track: " << track << std::endl;
}

Classic & Classic::operator=(const Classic & cl)
{
    if(this == & cl)
    {
        return *this;
    }
    Cd::operator=(cl);                          //копирование базовой части
    std::strcpy(track , cl.track);
    return *this;
}
