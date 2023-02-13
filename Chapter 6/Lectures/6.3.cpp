// ifelseif.cpp -- использование оператора if else if else
#include <iostream>
const int fave = 27;
int main()
{
    using namespace std;
    int n;
    cout << "Enter a number in the range 1-100 to find ";
    cout << "my favourite number: ";
    do
    {
        cin >> n;
        if( n < fave)
            cout << "Too low -- guess again: ";
        else if (n > fave)
            cout << "Too high -- guess again: ";
        else
            cout << fave << " is right!\n";
    } while (n != fave);
    return 0;
}
