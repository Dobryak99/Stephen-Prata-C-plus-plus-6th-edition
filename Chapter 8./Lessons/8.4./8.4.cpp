// swaps.cpp --обмен значаениями с помощью ссылок и указателей
#include <iostream>
void swapr(int & a, int & b);   // псевдонимы для int
void swapp(int * pa, int * pb);  // адреса int
void swapv(int a, int b);   //новый переменные
int main()
{
    using namespace std;
    int wallet1 = 300;
    int wallet2 = 350;
    cout << "Wallet1 = $" << wallet1 << endl;
    cout << "Wallet2 = $" << wallet2 << endl;
    // использование ссылок для обмена содержимого
    cout << "Using references to swap contents:\n";
    swapr(wallet1, wallet2);
    cout << "Wallet1 = $" << wallet1 <<endl;
    cout << "Wallet2 = $" << wallet2 <<endl;
    // использование указателей для обмена содержимого
    cout << "Using pointers to swap contents:\n";
    swapp(&wallet1, &wallet2);
    cout << "Wallet1 = $" << wallet1 <<endl;
    cout << "Wallet2 = $" << wallet2 <<endl;
    // попытка использования предачи по значению
    cout << "Trying to use passing by value:\n";
    swapv(wallet1, wallet2);
    cout << "Wallet1 = $" << wallet1 <<endl;
    cout << "Wallet2 = $" << wallet2 <<endl;
    return 0;
}
void swapr(int & a, int & b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void swapp(int * pa, int * pb)
{
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}
void swapv(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

