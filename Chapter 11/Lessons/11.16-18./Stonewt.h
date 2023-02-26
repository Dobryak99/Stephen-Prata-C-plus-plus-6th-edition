#ifndef Stonewt_hpp
#define Stonewt_hpp

//stonewt.h -- определение класса Stonewt

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
};

#endif
