#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
const int Size = 20;
struct Donators
{
    string name;
    double sum;
};
int main()
{
    int amount;
    char filename[Size];
    cout << "Enter the name of the file: ";
    cin.getline(filename, Size);
    ifstream File;
    File.open(filename);
    if(!File.is_open())
    {
        cout << "Couldn't open the file.\n";
        cout << "Programm terminating.\n";
        exit(EXIT_FAILURE);
    }
    File >> amount;
    Donators * pDonators = new Donators[amount];
    while(File.good())
    {
        for(int i = 0 ; i < amount; i++)
        {
            File.get();
            getline(File, pDonators[i].name);
            File >> pDonators[i].sum;
        }
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
    File.close();
    return 0;
}
