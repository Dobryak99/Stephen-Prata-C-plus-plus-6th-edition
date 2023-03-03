#include "CD2.h"
#include <cstring>
#include <iostream>



//Методы базового класса
Cd::Cd(const char * s1,const std::string & s2, int n, double x)
{
    performance = new char[std::strlen(s1) + 1];
    std::strcpy(performance, s1);
    label = s2;
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d)
{
    performance = new char[std::strlen(d.performance) + 1];
    std::strcpy(performance, d.performance);
    label = d.label;
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd()
{
    performance = new char[1];
    performance[0] = '\0';
    label = '\0';
    selections = 0;
    playtime = 0.0;
}

Cd::~Cd()
{
    delete [] performance;
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
    delete [] performance;
    performance = new char[std::strlen(d.performance) + 1];
    std::strcpy(performance, d.performance);
    label = d.label;
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

//Методы производного класса
Classic::Classic(const char * t,const char * s1,const std::string & s2, int n, double x) : Cd(s1,s2,n,x)
{
    track = new char[std::strlen(t) + 1];
    std::strcpy(track, t);
}

Classic:: Classic(const char * t, const Cd & d) : Cd(d)
{
    track = new char[std::strlen(t) + 1];
    std::strcpy(track, t);
}
Classic::Classic() : Cd()
{
    track = new char[1];
    track[0] = '\0';
}

Classic::~Classic()
{
    delete [] track;
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
    delete [] track;
    track = new char[std::strlen(cl.track) + 1];
    std::strcpy(track, cl.track);
    return *this;
}
