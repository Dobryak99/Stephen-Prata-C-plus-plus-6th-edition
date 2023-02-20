#ifndef _SALES_H_
#define _SALES_H_

namespace SALES
{
    const int QUARTERS = 4;
    struct Sales
    {
        double sales[QUARTERS];
        double average;
        double max;
        double min;
    };

    void setSales(Sales & s, const double ar[], int n);

    void setSales(Sales & s);

    void showSales(const Sales & s);

    double find_avg(const double arr[], int n);

    double find_max(const double arr[], int n);

    double find_min(const double arr[], int n);

}

#endif
