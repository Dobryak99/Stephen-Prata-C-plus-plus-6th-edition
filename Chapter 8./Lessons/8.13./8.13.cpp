// twoswap.cpp -- специализация переопределяет шаблон
#include <iostream>
template <typename T>
void Swap(T &a, T &b);
struct job
{
    char name[40];
    double salary;
    int floor;
};
//явная специализация
template<> void Swap <job>(job &j1, job &j2);
void Show(job &j);
int main()
{
    using namespace std;
    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap(i,j);     //генерирует void Swap(int &, int &)
    cout << "Now i, j = " << i << ", " << j << ".\n";
    job sue = {"Susan Yaffee", 73000.60, 7};
    job sidney ={"Sidney Yaffee", 78060.72, 9};
    cout << "Before job swapping:\n";
    Show(sue);
    Show(sidney);
    Swap(sue, sidney);    //используется void swap(job &, job &)
    cout << "After job swapping:\n";
    Show(sue);
    Show(sidney);
    return 0;
}
template <typename T>
void Swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}
//обмениваются только содержимым полей salary and floor структуры  job
template<> void Swap<job>(job &j1, job &j2) // специализация
{
    double t1;
    int t2;
    t1 = j1.salary;
    j1.salary = j2.salary;
    j2.salary = t1;
    t2 = j1.floor;
    j1.floor = j2.floor;
    j2.floor = t2;
}
void Show(job &j)
{
    using namespace std;
    cout << j.name << ": $" << j.salary << " on floor " << j.floor << endl;
}
