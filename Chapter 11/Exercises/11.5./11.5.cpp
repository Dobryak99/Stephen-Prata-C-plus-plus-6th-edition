#include "11.5.h"

Stonewt::Stonewt()
{
    mode = ST;
    stone = pds_left = pounds = 0;
}

Stonewt::Stonewt(double lbs, Mode form)
{
    mode = form;
    if(mode == ST)
    {
        stone = (int)lbs / Lbs_per_stn;
        pds_left = (int)lbs % Lbs_per_stn + lbs - (int)lbs;
        pounds = lbs;
    }else if(mode == INTLBS)
    {
        stone = (int)lbs / Lbs_per_stn;
        pds_left = (int)lbs % Lbs_per_stn + lbs - (int)lbs;
        pounds = (int)lbs;
    }else if(mode == DBLLBS)
    {
        stone = (int)lbs / Lbs_per_stn;
        pds_left = (int)lbs % Lbs_per_stn + lbs - (int)lbs;
        pounds = lbs;
    }else{
        std::cout << "Incorrect argument to Stonewt() -- ";
        std::cout << "weight set to 0\n";
        stone = pds_left = pounds = 0;
    }
}

Stonewt::~Stonewt()
{

}

Stonewt Stonewt::operator+(const Stonewt & st) const
{
    double pds = pounds + st.pounds;
    Stonewt sum = pds;
    return sum;
}

Stonewt Stonewt::operator-(const Stonewt & st) const
{
    double pds = pounds - st.pounds;
    Stonewt sub = pds;
    return sub;
}

Stonewt Stonewt::operator*(const Stonewt & st) const
{
    double pds = pounds * st.pounds;
    Stonewt mult = pds;
    return mult;
}

void Stonewt::set_ST()
{
    mode = ST;
}

void Stonewt::set_INTLBS()
{
    mode = INTLBS;
}

void Stonewt::set_DBLLBS()
{
    mode = DBLLBS;
}

std::ostream & operator<<(std::ostream & os, const Stonewt & st)
{
    if(st.mode == Stonewt::ST)
    {
        os << "Stone: " << st.stone << ", pounds: " << st.pds_left << std::endl;
    }else if(st.mode == Stonewt::INTLBS)
    {
        os << "Pounds: " << int(st.pounds) << std::endl;
    }else if(st.mode == Stonewt::DBLLBS)
    {
        os << "Pounds: " << st.pounds << std::endl;
    }else{
        os << "Object mode is invalid.\n";
    }
    return os;
}
