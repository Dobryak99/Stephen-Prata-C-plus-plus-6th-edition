// or.cpp -- использование логической операции "ИЛИ"
#include <iostream>
int main()
{
    using namespace std;
    cout << "This program may reformat your hard disk "
    "and destroy all your data.\n"
    "Do you wish to continue? <y/n> ";
    char ch;
    cin >> ch;
    if(ch == 'y' || ch == 'Y')
        cout << "You were warned!\a\a\n";
    else if(ch == 'n' || ch == 'N')
        cout << "A wise choice....bye\n";
    else
        cout << "That wasn't a y or n! Apparantly you "
        "can't follow instructions, so "
        "I'll trash your disk anyway\a\a\n";
    return 0;
}
