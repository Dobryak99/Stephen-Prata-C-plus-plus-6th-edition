// not.cpp -- использование логической операции "НЕ"
#include <iostream>
#include <climits>
bool is_int(double);
int main()
{
    using namespace std;
    double num;
    cout << "Yo, dude! Enter an integer value: ";
    cin >> num;
    while(!is_int(num))    //продолжать пока num не является int
    {
        cout << "Out of range -- please try again: ";
        cin >> num;
    }
    int val = int (num);
    cout << "You have entered the integer " << val << "\nBye.\n";
    return 0;
}
bool is_int(double x)    //проверка предельных значений climits
{
    if(x <= INT_MAX && x >= INT_MIN)
        return true;
    else
        return false;
}
