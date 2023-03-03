#include "CD2.h"
//#include "CD2.cpp"
#include <iostream>

void Bravo(const Cd &);

using namespace std;


int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
    Cd * pcd = &c1;

    //непосредственное использование объектов
    cout << "Using objects directly:\n";
    c1.Report();
    c2.Report();

    //ИСпользование указателя на объекты cd*
    cout << "Using type cd* pointer to objects:\n";
    pcd -> Report();
    pcd = &c2;
    pcd -> Report();

    //Вызов функции с аргументом ссылко на Cd
    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);

    //Тестирование присваивания
    cout << "Testing assignment:\n";
    Classic copy;
    copy = c2;
    copy.Report();
    return 0;
}


void Bravo(const Cd & disk)
{
    disk.Report();
}
