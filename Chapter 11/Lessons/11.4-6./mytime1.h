//mytime1.h -- класс Time после перегрузки операции
#ifndef MYTIME1_HPP_
#define MYTIME1_HPP_

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
    Time operator+(const Time & t) const;
    void show()const;
};

#endif
