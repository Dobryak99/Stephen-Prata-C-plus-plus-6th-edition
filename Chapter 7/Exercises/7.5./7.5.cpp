#include <iostream>
long double factorial(int number);
using namespace std;
int main()
{
    int integer;
    cout << "Enter any integer you want: ";
    while(cin >> integer)
    {
        cout << "Factorial of " << integer << " is " << factorial(integer) << endl;
        cout << "Enter another integer(q to quit): ";
    }
    cout << "Bye!\n";
    return 0;
}
long double factorial(int number)
{
    if(number == 0)
    {
        return 1;
    }
    else if(number < 0)
    {
        return 0;
    }
    else
    {
        return number * factorial(number - 1);
    }
}
