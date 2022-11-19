#include <iostream>
int main()
{
    using namespace std;
    cout << "Enter amount of money: ";
    int amount;
    cin >> amount;
    for(int i = amount; amount != 0; i = i + amount)
    {
        cout << "Your savings now are: " << i << "$";
        cout << endl << "Enter another amount of money: ";
        cin >> amount;
    }
    cout << "You didn't earn money today.";
    return 0;
}
