#include <iostream>
using namespace std;
const int Seasons = 4;
const char * Seasons_name[] = {"Spring", "Summer", "Fall", "Winter"};

struct expenses
{
    double ar[Seasons];
};

void fill(expenses *a)
{
    for(int i = 0; i < Seasons; i++)
    {
        cout << "Enter " << Seasons_name[i] << " expenses: ";
        cin >> a -> ar[i];
    }
}


void show(expenses * a)
{   
    double total = 0.0;
    cout << "\n!!!Expenses!!!\n\n";
    for(int i = 0; i <  Seasons; i++)
    {
        cout << Seasons_name[i] << ": $" << a -> ar[i] << endl;
        total += a -> ar[i];
    }
    cout << "Total expenses : $" << total << endl;
}


int main()
{
    expenses year;
    fill(&year);
    show(&year);
    return 0;
}
