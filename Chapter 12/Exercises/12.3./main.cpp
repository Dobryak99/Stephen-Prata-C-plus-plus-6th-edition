#include <iostream>
#include "stock.h"
#include "stock.cpp"

const int STKS = 4;
int main()
{
    Stock stocks[STKS] = {
        Stock("Nike", 12, 20.0),
        Stock("Apple", 200, 2.0),
        Stock("Microsoft", 130, 3.25),
        Stock("Tesla", 60, 6.5),
    };
    //Stock test;                                       //для проверки оператора присваивания и копирования
    //test = stocks[3];
    std::cout << "Stock holdings:\n";
    int st;
    for(st = 0; st < STKS; st++)
    {
        std::cout << stocks[st] << std::endl;
    }
    const Stock * top = &stocks[0];
    for(st = 1; st < STKS; st++)
    {
        top = &top ->topval(stocks[st]);
    }
    std::cout << "Most valuable holding:\n";
    std::cout << *top << std:: endl;

    //std::cout << "Just for test. test = stocks[3]: " << test << std::endl;
    return 0;
}
