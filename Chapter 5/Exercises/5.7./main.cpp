#include <iostream>
#include <string>
using namespace std;
struct car
{
    string name;
    int year;
};
int main()
{
    cout << "How many cars should put into the catalogue: ";
    int number;
    cin >> number;
    car * pcatalogue = new car[number];
    for (int i = 1; i <= number; i++)
    {
        cout << "Car #" << i << ".\n";
        cout << "Enter manufacturer: ";
        cin.get();
        getline(cin,pcatalogue[i].name);
        cout << "Enter its production year: ";
        cin >> pcatalogue[i].year;
    }
    cout << "Here is your collection:\n";
    for (int j = 1; j <= number; j++)
    {
        cout << pcatalogue[j].year << " " << pcatalogue[j].name << endl;
    }
    delete [] pcatalogue;
    return 0;
}
