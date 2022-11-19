#include <iostream>
#include <cstring>
int main()
{
    using namespace std;
    char ch[10];
    int count = 0;
    cout << "Enter words (if you want to stop, enter \"done\"): "<< endl;
    while(strcmp(ch, "done"))
    {
        count++;
        cin >> ch;
    }
    cout << "You entered: " << count - 1 << " words.";
    return 0;
}
