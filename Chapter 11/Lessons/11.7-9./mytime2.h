//mytime2.h -- класс Time после перегрузки операции
#ifndef MYTIME2_HPP_
#define MYTIME2_HPP_

class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    Time operator+(Time & t) const;
    Time operator-(Time & t) const;
    Time operator*(double n) const;
    void Show() const;
};


#endif
