// block.cpp -- использование блока
#include <iostream>
int main()
{
    using namespace std;
    cout << "The amazing accounto will sum and averaage ";
    cout << "five numers for you.\n";
    cout << "Please enter five values: " << endl;
    double number;
    double sum = 0.0;
    for (int i = 1; i <= 5; i++)
    {
        cout << "value " << i << ": ";   //начало блока
        cin >> number;                   // ввоод числа
        sum += number;
    }                                    // конец блока
    cout << "Five exquisite choices indeed! ";
    cout << "They sum to " << sum << endl;
    cout << "and average to " << sum / 5 << endl;
    cout << "The amazing accounto bids you adieu!\n";
    return 0;
}
