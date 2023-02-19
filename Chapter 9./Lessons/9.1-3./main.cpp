//file1.cpp -- пример программы, состоящей из трех файлов
#include <iostream>
#include "coordin.h"

using namespace std;
int main()
{
    rect rplace;
    polar pplace;
    
    cout << "Enter the x and y values: ";
    while(cin >> rplace.x >> rplace.y)
    {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "Next two numbers(q to quit): ";
    }
    cout << "Done!\n";
    return 0;
}
