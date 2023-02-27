#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>

class Stonewt
{
    public:
        enum Mode{ST, INTLBS, DBLLBS};
    private:
        static const int Lbs_per_stn = 14;
        int stone;
        double pds_left;
        double pounds;
        Mode mode;
    public:
        Stonewt();
        Stonewt(double lbs, Mode form = ST);
        ~Stonewt();
        Stonewt operator+(const Stonewt & st) const;
        Stonewt operator-(const Stonewt & st) const;
        Stonewt operator*(const Stonewt & st1) const;
        void set_ST();
        void set_INTLBS();
        void set_DBLLBS();
        friend std::ostream & operator<<(std::ostream & os, const Stonewt & st);
};

#endif
