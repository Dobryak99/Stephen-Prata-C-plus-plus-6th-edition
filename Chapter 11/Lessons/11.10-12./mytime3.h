//mytime2.h -- класс Time после перегрузки операции
#ifndef MYTIME3_HPP_
#define MYTIME3_HPP_
#include <iostream>

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
    friend Time operator*(double m, const Time & t){return t * m;} //   встроенная функция
    friend std::ostream &operator<<(std::ostream & os, const Time & t);
};


#endif
