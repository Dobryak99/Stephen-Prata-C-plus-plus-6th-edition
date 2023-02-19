// static.cpp --  использование статической локальной переменной
#include <iostream>

const int ArSize = 10;

void strcount(const char * str);

int main()
{
    using namespace std;
    char input[ArSize];
    char next;
    cout << "Enter line: \n";
    cin.get(input,ArSize);
    while(cin)
    {
        cin.get(next);
        while(next != '\n')   //строка не помещается
        {
            cin.get(next);     // избавиться от остатка
        }
        strcount(input);
        cout << "Enter next line(enmpty line to quit): \n";
        cin.get(input,ArSize);
    }
    cout << "Goodbye!\n";
    return 0;
}

void strcount(const char * str)
{
    using namespace std;
    static int total = 0;
    int count  = 0;
    cout << "\"" << str << "\" contains ";
    while(*str++)
    {
        count++;
    }
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}
