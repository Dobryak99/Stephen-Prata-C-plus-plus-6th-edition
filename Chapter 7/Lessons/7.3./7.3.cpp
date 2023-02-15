// twoarg.cpp -- функция с двумя аргументами
#include <iostream>
using namespace std;
void n_chars(char, int);
int main()
{
    int times;
    char ch;
    cout << "Enter a character: "; //ввод символа
    cin >> ch;
    while(ch != 'q')
    {
        cout << "Enter an integer: ";
        cin >> times;
        n_chars(ch, times);
        cout << "\nEnter another character or press the q-key to quit: ";
        cin >> ch;
    }
    cout << "The value of times is " << times << ".\n";
    cout << "Bye\n";
    return 0;
}
void n_chars(char a, int b)
{
    while (b-- > 0)    //продолжение пока b не достигнет 0
        cout << a;
}
