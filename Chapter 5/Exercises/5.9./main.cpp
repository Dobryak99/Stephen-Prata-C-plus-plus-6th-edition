#include <iostream>
#include <string>
int main()
{
    using namespace std;
    cout << "Enter word (if you want to stop, enter \"done\"):";
    int count = 0;
    string word;
    while (word != "done")
    {
        count++;
        cin >> word;
    }
    cout << "Total: " << count - 1 << " words.\n";
    return 0;
}
