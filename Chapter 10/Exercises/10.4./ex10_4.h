#ifndef _EX10_4_H_
#define _EX10_4_H_

namespace SALES
{
    static const int QUARTERS = 4;
    class Sales
    {
        private:
            double sales[QUARTERS];
            double average;
            double max;
            double min;
            double find_avg(const double arr[], int n);

            double find_max(const double arr[], int n);

            double find_min(const double arr[], int n);
        public:
            Sales();
            Sales(const double arr[], int n);
            ~Sales();

            void setSales();

            void showSales() const;
    };
}

#endif
