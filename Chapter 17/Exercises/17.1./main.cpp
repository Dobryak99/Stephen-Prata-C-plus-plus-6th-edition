#include <iostream>

int main()
{
    using namespace std;

    cout << "Enter a string with \"$\": ";
    char ch;
    cin.get(ch);
    int count = 0;
    while(ch != '$')
    {
        count++;
        cin.get(ch);
    }
    cout << "The number of symbols up to symbol \"$\": ";
    cout << count << endl;
    cout << "The next input character is " << ch << endl;
    return 0;

}
