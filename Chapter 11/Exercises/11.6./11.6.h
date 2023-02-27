#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>
class Stonewt
{
    private:
        enum{Lbs_per_stn = 14};
        int stone;
        double pds_left;
        double pounds;
    public:
        Stonewt(double lbs);
        Stonewt();
        ~Stonewt();
        int comp_val() const {return stone;};

        // comparison operators
        bool operator>(const Stonewt & st) const;
        bool operator<(const Stonewt & st) const;
        bool operator>=(const Stonewt & st) const;
        bool operator<=(const Stonewt & st) const;
        bool operator==(const Stonewt & st) const;
        bool operator!=(const Stonewt & st) const;

        //Set values in class
        void set_val();


        // Friends
        friend std::ostream & operator<<(std::ostream & os, const Stonewt & st);

};

#endif
