// secref.cpp -- определение и использование ссылки
#include <iostream>
int main()
{
    using namespace std;
    int rats;
    int & rodents = rats;
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents << endl;
    int bunnies = 50;
    rodents = bunnies;
    cout << "bunnies = " << bunnies;
    cout << ", rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    cout << "bunnies address = " << &bunnies;
    cout << ", rodents address = " <<  &rodents << endl;
    return 0;
}
