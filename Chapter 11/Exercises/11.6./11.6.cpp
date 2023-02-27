#include "11.6.h"

Stonewt::Stonewt(double lbs)
{
    stone = (int)lbs / Lbs_per_stn;
    pds_left = (int)lbs % Lbs_per_stn + lbs - (int)lbs;
    pounds = lbs;
}

Stonewt::Stonewt()
{
    stone = pds_left = pounds = 0;
}

Stonewt::~Stonewt()
{

}


void Stonewt::set_val()
{
    std::cin >> pounds;
    stone = (int)pounds / Lbs_per_stn;
    pds_left = (int)pounds % Lbs_per_stn + pounds - (int)pounds;
}

bool Stonewt::operator>(const Stonewt & st) const
{
    return pounds > st.pounds;
}

bool Stonewt::operator<(const Stonewt & st) const
{
    return pounds < st.pounds;
}

bool Stonewt::operator>=(const Stonewt & st) const
{
    return pounds >= st.pounds;
}

bool Stonewt::operator<=(const Stonewt & st) const
{
    return pounds <= st.pounds;
}

bool Stonewt::operator==(const Stonewt & st) const
{
    return pounds == st.pounds;
}

bool Stonewt::operator!=(const Stonewt & st) const
{
    return !(pounds == st.pounds);
}

std::ostream & operator<<(std::ostream & os, const Stonewt & st)
{
    os << st.pounds;
    return os;
}
