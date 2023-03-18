// lambda1.cpp -- использование лямбда-выражений
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

const long Size =390000L;

int main()
{
    using std::cout;
    std::vector<int> numbers(Size);
    std::srand(std::time(0));
    std::generate(numbers.begin(), numbers.end(), std::rand);
    cout << "Sample size = " << Size << '\n';                      //размер выборки
    
    // использование лямда-функции
    int count3 = std::count_if(numbers.begin(), numbers.end(), [](int x){return x % 3 == 0;});
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    
    int count13 = 0;
    std::for_each(numbers.begin(), numbers.end(), [&count13](int x){count13 += x % 13 == 0;});
    cout << "Count of numbers divisible by 13: " << count13 << '\n';
    
    //использование одиночного лямбда-выражения
    count3 = count13 = 0;
    std::for_each(numbers.begin(), numbers.end(), [&](int x){count13 += x % 13 == 0;count3 += x % 3 == 0;});
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    cout << "Count of numbers divisible by 13: " << count13 << '\n';
    return 0;
}
