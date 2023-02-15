// arrfun4.cpp -- функция с диапазоном массива
#include <iostream>
const int ArSize = 8;
int sum_arr(const int * begin, const int * end);
int main()
{
    using namespace std;
    int cookies[ArSize]= {1,2,4,8,16,32,64,128};
    int sum = sum_arr(cookies, cookies + ArSize);
    cout << "Total cookies eaten: " << sum << endl;
    sum = sum_arr(cookies, cookies + 3);    //три первых элемента
    cout << "First three eaters ate: " << sum << " cookies.\n";
    sum = sum_arr(cookies + 4, cookies + 8);   //четыре последних элемента
    cout << "Last four eaters ate " <<  sum << " cookies.\n";
    return 0;
}
int sum_arr(const int * begin, const int * end)
{
    const int * pt;
    int total = 0;
    for (pt = begin; pt != end; pt++)
    {
        total = total + *pt;
    }
    return total;
}
