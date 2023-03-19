#include <iostream>
#include <vector>
#include <iterator>
#include <initializer_list>

template <typename T>
T average_list(std::initializer_list<T> val);


int main()
{
    using namespace std;

    //список double выведен из содержимого списка
    auto q = average_list({15.4, 10.7, 9.0});
    cout << q << endl;

    //Список int выведен из содержимого списка
    cout << average_list({20,30,19,45,38}) << endl;

    //принудительное использование списка double
    auto ad = average_list<double>({'A', 70, 65.33});
    cout << ad << endl;
    return 0;
}

template <typename T>
T average_list(std::initializer_list<T> val)
{
    T sum = 0;
    int count = 0;
    for(auto iter = val.begin(); iter != val.end(); iter++, ++count)
    {
        sum += (*iter);
    }
    return sum / count;

}
