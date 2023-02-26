//stonewt1.h -- определение класса Stonewt
#ifndef STONEWT1_HPP_
#define STONEWT1_HPP_

class Stonewt
{
private:
    enum{Lbs_per_stn = 14};  //фунтов в стоун
    int stone;  //полных стоунов
    double pds_left;    //дробное число фунтов
    double pounds;  //общий вес в фунтах
public:
    Stonewt(double lbs);    //конструктор для значения в фунтах
    Stonewt(int stn, double lbs);   //конструктор для значений в стоунах и фунтах
    Stonewt();  //конструктор по умолчанию
    ~Stonewt();
    void show_lbs() const;
    void show_stn() const;
    //функции преобразования
    operator int() const;
    operator double() const;
};

#endif
