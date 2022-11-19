// forloop.cpp -- представление цикла for
#include <iostream>
int main()
{
    using namespace std;
    int i;   //создание счетчика
    //инициализация; проверка; обновление
    for (i = 0; i < 5; i++)
        cout << "C++ knows loops.\n";
    cout << "C++ knows when to stop.\n";
    return 0;
}
