#include "wine.h"

Wine::Wine(const char * l,int y, const int yr[], const int bt[]) : label(l), years(y)
{
    // доступ к первому значению объекта pair(std::valarray<int>) с изменением его размера на количество лет
    data.first.resize(years);
    // доступ ко второму значению объекта pair(std::valarray<int>) с изменением его размера на количество лет
    data.second.resize(years);
    for(int i = 0; i < years; i++)
    {
        data.first[i] = yr[i];  //установка значений из переданного массива в первый std::valarray<int>
        data.second[i] = bt[i]; //установка значений из переданного массива во второй std::valarray<int>
    }
}

Wine::Wine(const char * l, int y) : label(l), years(y)
{
    data.first = 0;
    data.second = 0;
}

void Wine::GetBottles()
{
    data.first.resize(years);
    data.second.resize(years);
    std::cout << "Enter " << label << " data for " << years << " year(s):\n";
    for(int i = 0; i < years; i++)
    {
        std::cout << "Enter years: ";
        std::cin >> data.first[i];
        std::cout << "Enter bottles for that year: ";
        std::cin >> data.second[i];
    }
}

void Wine::Show() const
{
    std::cout << "Wine:\t" << label << std::endl;
    std:: cout << "\tYear" << "\tBottles" << std::endl;
    for(int i = 0; i < years; i++)
    {
        std::cout << "\t" << data.first[i] << "\t" << data.second[i] << std::endl;
    }
}

const std::string & Wine::Label() const
{
    return label;
}

int Wine::sum() const
{
    int summary = 0;
    for(int i = 0; i < years; i++)
    {
        summary += data.second[i];
    }
    return summary;
}



