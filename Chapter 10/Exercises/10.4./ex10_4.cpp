#include <iostream>
#include "ex10_4.h"

namespace SALES
{
    SALES::Sales::Sales()
    {
        double sales[QUARTERS] = {0,0,0,0};
        double  average = 0;
        double max = 0;
        double min = 0;
    }

    SALES::Sales::Sales(const double arr[], int n)
    {
        average = find_avg(arr, n);
        min = find_min(arr, n);
        max = find_max(arr,n);
        for(int i = 0; i < QUARTERS; i++)
        {
            sales[i] = 0;
        }
    }

    SALES::Sales::~Sales()
    {

    }

    void SALES::Sales::setSales()
    {
        std::cout << "Enter sales for 4 quarters!\n";
        for(int i = 0; i < QUARTERS; i++)
        {
            std::cout << "QUARTER #" << i + 1 << ":";
            std::cin >> sales[i];
        }
        average = find_avg(sales, QUARTERS);
        min = find_min(sales, QUARTERS);
        max = find_max(sales, QUARTERS);
    }

    void SALES::Sales::showSales() const
    {
        std::cout << "\nAverage =  " << average << std::endl;
        std::cout << "Maximum = " << max << std::endl;
        std::cout << "Miminum = " << min << std::endl;
    }


    double SALES::Sales::find_avg(const double arr[], int n)
    {
        double avg = 0;
        for(int i = 0; i < n; i++)
        {
            avg += arr[i];
        }
        return avg / n;
    }

    double SALES::Sales::find_min(const double arr[], int n)
    {
        double min = arr[0];
        for(int i = 1; i < n; i++)
        {
            if(arr[i] < min)
                min = arr[i];
        }
        return min;
    }

    double SALES::Sales::find_max(const double arr[], int n)
    {
        double max = arr[0];
        for(int i = 1; i < n; i++)
        {
            if(arr[i] > max)
                max = arr[i];
        }
        return max;
    }


}
