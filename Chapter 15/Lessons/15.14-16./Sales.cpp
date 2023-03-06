//sales.cpp -- реализация Sales
#include "Sales.hpp"

using std::string;

Sales::bad_index::bad_index(int ix, const string & s) : std::logic_error(s), bi(ix)
{
    
}

Sales::Sales(int yy)
{
    year = yy;
    for(int i = 0; i < MONTH; ++i)
    {
        gross[i] = 0;
    }
}

Sales::Sales(int yy, const double * gr, int n)
{
    year = yy;
    int lim = (n < MONTH) ? n : MONTH;
    int i;
    for(i = 0; i < lim; ++i)
    {
        gross[i] = gr[i];
    }
    //для i > n и i < MONTH
    for(; i < MONTH; ++i)
    {
        gross[i] = 0;
    }
}

double Sales::operator[](int i) const{              //для получения значения
    if(i < 0 || i >= MONTH)
    {
        throw bad_index(i);
    }
    return gross[i];
}

double & Sales::operator[] (int i)                  //для изменения значения
{
    if(i < 0 || i >= MONTH)
    {
        throw bad_index(i);
    }
    return gross[i];
}

LabeledSales::nbad_index::nbad_index(const string & lb, int ix, const string & s) : Sales::bad_index(ix,s)
{
    lbl = lb;
}

LabeledSales::LabeledSales(const string & lb, int yy, const double * gr, int n) : Sales(yy,gr,n)
{
    label = lb;
}

LabeledSales::LabeledSales(const string & lb, int yy) : Sales(yy)
{
    label = lb;
}

double LabeledSales::operator[](int i) const
{
    if(i < 0 || i > MONTH)
    {
        throw nbad_index(Label(), i);
    }
    return Sales::operator[](i);
}

double & LabeledSales::operator[] (int i)
{
    if(i < 0 || i > MONTH)
    {
        throw nbad_index(Label(), i);
    }
    return Sales::operator[](i);
}
