#include <iostream>

long double sum_values()
{
    return 0;
}

template<typename T>
long double sum_values(const T &value)
{
    return value;
}

template <typename T, typename...Args>
double sum_values(const T & value, const Args&...args)
{
    long double sum = 0.0;
    sum += value + sum_values(args...);
    return sum;
}

int main()
{
    int x = 4, y = 15;
    double k = 43.21, l = 4.4345;
    std::cout << sum_values(x, y, k, l) << std::endl;
    return 0;
}
