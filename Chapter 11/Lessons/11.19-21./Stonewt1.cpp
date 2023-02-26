//stonewt1.cpp -- методы класса stonewt
#include <iostream>
#include "stonewt1.hpp"
using std::cout;

//Конструирует объект Stonewt из значений double
Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn;     //целочисленное деление
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

//Конструктор объекта Stonewt из стоунов и значений типа double
Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()
{
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()
{
    
}

void Stonewt::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds.\n";
}

void Stonewt::show_lbs() const
{
    cout << pounds << " pounds.\n";
}

Stonewt::operator int() const
{
    return int (pounds + 0.5);
}

Stonewt::operator double() const
{
    return pounds;
}
