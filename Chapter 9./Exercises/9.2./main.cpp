#include <iostream>
#include <string>

void strcount(const std::string & a);

int main()
{
    using namespace std;
    string input;
    cout << "Enter a line: ";
    getline(cin,input);
    while(input != "")
    {
        strcount(input);
        cout << "Enter next line(empty line to quit): ";
        getline(cin, input);
    }
    cout << "Bye.\n";
    return 0;
}

void strcount(const std::string & a)
{
    using namespace std;
    static int total = 0;
    int count = 0;
    int i = 0;
    cout << "\"" << a << "\"" << " contains:\n";
    while(a[i++])
    {
        if(a[i] == ' ')
        {
            count--;
        }
        count++;
    }
    total += count;
    cout << count << " characters.\n";
    cout << total << " characters total.\n";
}

