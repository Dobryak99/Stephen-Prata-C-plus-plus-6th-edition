#include <iostream>
const int Seasons = 4;
const char* Snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"};
void fill(double arr[], const char *[]);
void show(double arr[], const char *[]);
int main()
{
    using namespace std;
    double expenses[Seasons];
    fill(expenses, Snames);
    show(expenses, Snames);
    return 0;
}
void fill(double arr[], const char *[])
{
    using namespace std;
    for(int i = 0; i < Seasons; i++)
    {
        cout << "Enter " << Snames[i] << " expenses:";
        cin >> arr[i];
    }
}
void show(double arr[], const char *[])
{
    using namespace std;
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for(int i = 0; i < Seasons; i++)
    {
        cout << Snames[i] << ": $" << arr[i] << endl;
        total += arr[i];
    }
    cout << "Total expenses: $" << total << endl;
}
