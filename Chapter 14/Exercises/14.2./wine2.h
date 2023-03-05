#ifndef WINE2_H_
#define WINE2_H_

#include <iostream>
#include <string>
#include <valarray>

typedef std::valarray<int> ArrayInt;
typedef std::pair<ArrayInt, ArrayInt> PairArray;

class Wine : private std::string, private PairArray
{
    private:
        int years;
    public: 
        Wine(const char * l, int y, const int yr[], const int bt[]);
        Wine(const char * l, int y);
        ~Wine() {}
        void Show() const;
        void GetBottles();
        const std::string & Label() const;
        int sum();
};

#endif
