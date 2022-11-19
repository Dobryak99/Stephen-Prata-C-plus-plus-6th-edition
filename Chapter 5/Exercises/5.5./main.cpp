#include <iostream>
#include <string>
int main()
{
    using namespace std;
    string Month[12] =
    {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    int Sales[12];
    for (int month = 0; month < 12; ++month)
    {
        cout << "Enter quantity of sales in " << Month[month] << ":\t";
        cin >> Sales[month];
    }
    int sum;
    for (int i = 0; i < 12; i++)
    {
        sum = sum + Sales[i];
    }
    cout << "Sales per year: " << sum << endl;
    return 0;
}
