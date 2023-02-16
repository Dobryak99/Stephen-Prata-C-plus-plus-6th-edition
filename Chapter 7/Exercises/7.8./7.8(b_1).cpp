#include <iostream>
const int Seasons = 4;
const char* Snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"};
struct money
{
    double liabilities[Seasons];
};
void fill(money *a, const char *[]);
void show(money *a, const char *[]);
int main()
{
    using namespace std;
    money expenses;
    fill(&expenses, Snames);
    show(&expenses, Snames);
    return 0;
}
void fill(money *a, const char *[])
{
    using namespace std;
    for(int i = 0; i < Seasons; i++)
    {
        cout << "Enter " << Snames[i] << " expenses:";
        cin >> a -> liabilities[i];
    }
}
void show(money *a, const char *[])
{
    using namespace std;
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for(int i = 0; i < Seasons; i++)
    {
        cout << Snames[i] << ": $" << a -> liabilities[i] << endl;
        total += a -> liabilities[i];
    }
    cout << "Total expenses: $" << total << endl;
}
