#include <iostream>
#include "sales.h"

namespace SALES
{
    void setSales(Sales & s, const double arr[], int n)
    {
        for(int i = 0; i < n; i++)
        {
            s.sales[i] = arr[i];
            s.average = find_avg(s.sales, QUARTERS);
            s.max = find_max(s.sales, QUARTERS);
            s.min = find_min(s.sales, QUARTERS);
        }
        for(int i = 0; i < QUARTERS; i++)
        {
            s.sales[i] = 0;
        }
    }

    void setSales(Sales & s)
    {
        std::cout << "Enter sales for 4 quarters.\n";
        for(int i = 0; i < QUARTERS; i++)
        {
            std::cout << i + 1 << " quarter: ";
            std::cin >>  s.sales[i];
        }
        s.average = find_avg(s.sales, QUARTERS);
        s.max = find_max(s.sales, QUARTERS);
        s.min = find_min(s.sales, QUARTERS);
    }

    void showSales(const Sales & s)
    {
        std::cout << "\nAverage =  " << s.average << std::endl;
        std::cout << "Maximum = " << s.max << std::endl;
        std::cout << "Miminum = " << s.min << std::endl;
    }

    double find_avg(const double arr[], int n)
    {
        double avg = 0;
        for(int i = 0; i < n; i++)
        {
            avg += arr[i];
        }
        return avg / n;
    }

    double find_max(const double arr[], int n)
    {
        double max = arr[0];
        for(int i = 1; i < n; i++)
        {
            if(arr[i] > max)
                max = arr[i];
        }
        return max;
    }

    double find_min(const double arr[], int n)
    {
        double min = arr[0];
        for(int i = 1; i < n; i++)
        {
            if(arr[i] < min)
                min = arr[i];
        }
        return min;
    }
}
