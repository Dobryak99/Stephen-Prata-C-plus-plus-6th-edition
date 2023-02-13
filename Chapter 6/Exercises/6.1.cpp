#include <iostream>
#include <cctype>
int main()
{
    using namespace std;
    char ch;
    cout << "Enter sentence(type\'@\' to terminate): ";
    while ((cin.get(ch)) && ch != '@')
    {
    
        if(isdigit(ch))
        {
            cout << "\nIntegers are prohibited!!!\n"
            << "Enter letters: ";
        }
        else if(islower(ch))
        {
           cout << (char)toupper(ch);
        }
        else if(isupper(ch))
        {
            cout << (char)tolower(ch);
        }
        else
            cout << ch;
    }
    cout << "Done!\n";
    return 0;
}
