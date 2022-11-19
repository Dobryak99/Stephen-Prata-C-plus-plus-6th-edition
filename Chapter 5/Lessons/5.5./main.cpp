//bigstep.cpp -- цикл указанным пользователем шагом
#include <iostream>
int main()
{
    using std::cout; // объявление using
    using std::cin;
    using std::endl;
    cout << "Enter an integer: ";
    int by;        //ввод целого числа
    cin >> by;
    cout << "Counting by " << by << "s:\n";
    for (int i = 0; i < 100; i = i + by)
        cout << i << endl;
    return 0;
}
