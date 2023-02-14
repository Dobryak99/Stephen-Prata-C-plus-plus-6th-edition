#include <iostream>
#include <string>
using namespace std;
struct Donators
{
    string name;
    double sum;
};
int main()
{
    int amount;
    cout << "Enter the amount of Maecenas:";
    cin >> amount;
    Donators * pDonators = new Donators[amount];
    for(int i = 0 ; i < amount; i++)
    {
        cout << "Enter the name of Maecenas #" << i + 1 << ":";
        cin.get();
        getline(cin, pDonators[i].name);
        cout << "Enter the donation:";
        cin >> pDonators[i].sum;
    }
    cout << "\n=============================\n";
    cout << "\"Grand Patrons\"\n";
    for (int i = 0; i < amount; i++)
    {
        if(pDonators[i].sum >= 10000)
        {
            cout << pDonators[i].name << " donated " << pDonators[i].sum << "$\n";
        }
    }
    cout << "\n=============================\n";
    cout << "\"Patrons\"\n";
    for (int i = 0; i < amount; i++)
    {
        if(pDonators[i].sum < 10000)
        {
            cout << pDonators[i].name << endl;
        }
    }
    delete [] pDonators;
    return 0;
}
