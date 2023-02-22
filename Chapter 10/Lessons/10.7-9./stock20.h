
//stock20.h -- интерфейс класса Stock
//версия 0.2
#ifndef STOCK20_H_
#define STOCK20_H_
#include <string>

class Stock  // объявление класса
{
private:
    std::string company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() {total_val = shares * share_val;}
    
public:
    Stock();  //конструктор по умолчанию
    Stock(const std::string & co, int n = 0, double pr = 0.0);
    ~Stock();   // деструктор
    void buy(int num, double price);
    void sell(int num, double price);
    void update(double price);
    void show() const;
    const Stock & topval(const Stock & s) const;
};  //обратите внимание на точку с запятой в конце


#endif
