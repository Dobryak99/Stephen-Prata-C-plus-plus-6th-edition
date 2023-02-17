// firstref.cpp -- определение и использование ссылки
#include <iostream>
int main()
{
    using namespace std;
    int rats;
    int & rodents = rats;  //rodents является ссылкой
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    rodents++;
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents << endl;
    return 0;
}
