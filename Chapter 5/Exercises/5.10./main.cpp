#include<iostream>
using namespace std;
int main()
{
    int i;
    char s = '*';
    char d = '.';
    cout << "Enter figure: ";
    cin >> i;
    for (int n = 1; n <= i; n++)
    {
        for (int j = 0; j < i - n; j++)
            cout << d;
        for (int j = 0; j < n; j++)
            cout << s;
        cout << endl;
    }
    return 0;
}
