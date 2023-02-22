//stock10.h -- интерфейс класса Stock
//версия 0.1
#ifndef STOCK10_H_
#define STOCK10_H_
#include <string>

class Stock  // объявление класса
{
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() {total_val = shares * share_val;}
    
public:
    Stock();  //конструктор по умолчанию
    Stock(const std::string & co, long n = 0, double pr = 0.0);
    ~Stock();   // деструктор
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};  //обратите внимание на точку с запятой в конце


#endif
