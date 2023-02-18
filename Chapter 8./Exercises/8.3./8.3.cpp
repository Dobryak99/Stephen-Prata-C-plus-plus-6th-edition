#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string to_up(string & a);

int main()
{
    string word;
    cout << "Enter string(q to quit): ";
    while(true)
    {
        getline(cin,word);
        if(word[0] != 'q')
        {
            cout << to_up(word) << endl;
            cout << "Enter string(q to quit): ";
        }else{
            cout << "\nBye!\n";
            break;
        }
    }
    return 0;
}

string to_up(string &a)
{  
    for(int i = 0; a[i]; i++)
    {
        a[i] = toupper(a[i]);
    }
    return a;
}
