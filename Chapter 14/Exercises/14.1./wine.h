#ifndef WINE_H_
#define WINE_H_

#include <iostream>
#include <string>
#include <valarray>

typedef std::valarray<int> ArrayInt;
typedef std::pair<ArrayInt,ArrayInt> PairArray;             //объект pair объединяет два значения одновременно

class Wine
{
    private:
        std::string label;
        PairArray data;             //первый элемент хранит года,  второй элемент хранит количество бутылок
        int years;
    public:
        Wine(const char * l, int y, const int yr[], const int bt[]);
        Wine(const char * l, int y);
        ~Wine() {}
        void GetBottles();
        const std::string & Label() const;
        int sum() const;
        void Show() const;
};

#endif
