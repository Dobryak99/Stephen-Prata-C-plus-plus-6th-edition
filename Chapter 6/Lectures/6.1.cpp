// if.cpp -- использование оператора if
#include <iostream>
int main()
{
    using std:: cin;
    using std:: cout;
    char ch;
    int space = 0;
    int total = 0;
    cin.get(ch);
    while (ch != '.')
    {
        if(ch == ' ')
            ++space;
        ++total;
        cin.get(ch);
    }
    cout << space << " spaces, " << total;
    cout << " characters total in sentence\n";
    return 0;
}

