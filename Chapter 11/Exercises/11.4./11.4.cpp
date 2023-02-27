#include <iostream>
#include "11.4.h"

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h)
{
    hours  += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time operator+(const Time & t, const Time & t1)
{
    Time sum;
    sum.minutes = t1.minutes + t.minutes;
    sum.hours = t1.hours + t.hours + sum.minutes / 60;
    sum.minutes = sum.minutes % 60;
    return sum;
}

Time operator-(const Time & t, const Time & t1)
{
    Time diff;
    int res1, res2;
    res1 = t.minutes + t.hours * 60;
    res2 = t1.minutes + t1.hours * 60;
    diff.minutes = (res1 - res2) % 60;
    diff.hours = (res1 - res2) / 60;
    return diff;
}

Time operator*(const Time & t, double n)
{
    Time result;
    long totalminutes = (t.hours * 60 + t.minutes) * n;
    result.minutes = totalminutes % 60;
    result.hours = totalminutes / 60;
    return  result; 
}

std::ostream & operator<<(std::ostream & os, const Time & t)
{
    os << t.hours << " hours, " << t.minutes << " minutes.";
    return os;
}                    
