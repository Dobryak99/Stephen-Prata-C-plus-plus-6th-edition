// variadic1.cpp -- использование рекурсии для распаковки пакета параметров
#include <iostream>
#include <string>

// определение для 0 параметров -- завершение вызова
void show_list3() {}

//определение для 1 и более параметров
template<typename T, typename...Args>
void show_list3(T value, Args...args)
{
    std::cout << value << ", ";
    show_list3(args...);
}

int main()
{
    int n = 14;
    double x = 2.71828;
    std::string mr = "Mr. String object!";
    show_list3(n,x);
    show_list3(x*x, '!', 7, mr);
    return 0;
}
