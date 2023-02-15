// arrfun1.cpp -- функция с аргументом-массивом
#include <iostream>
const int ArSize = 8;
int sum_arr(int arr[], int n);    // прототип
int main()
{
    using namespace std;
    int cookies[ArSize] = {1,2,4,8,16,32,64,128};
    // Некоторые системы требуют предварить int словом static, чтобы разрешить инициализировать массив
    int sum = sum_arr(cookies, ArSize);
    cout << "Total cookies eaten: " << sum << "\n";
    return 0;
}
int sum_arr(int arr[], int n)
{
    int total = 0;
    for(int i = 0; i < n; i++)
        total = total + arr[i];
    return total;
}
