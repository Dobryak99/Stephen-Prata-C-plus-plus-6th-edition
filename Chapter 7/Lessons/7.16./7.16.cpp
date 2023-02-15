// recur.cpp -- использование рекурсии
#include <iostream>
void countdown(int n);
int main()
{
    countdown(4);  //вызов рекурсии функции
    return 0;
}
void countdown(int n)
{
    using namespace std;
    cout << "counting down... " << n << endl;
    if(n > 0)
        countdown(n - 1);   //функция вызывает саму себя
    cout << n << ": Kaboo!\n";
}
