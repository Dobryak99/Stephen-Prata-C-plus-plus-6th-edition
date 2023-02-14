#include <iostream>
#include <cctype>
using namespace std;
int main()
{
    double salary;
    cout << "Enter your salary:";
    cin >>  salary;
    while(salary >= 0 && salary != isalpha(salary))
    {
        if(salary <= 5000)
        {
            cout << "Your tax is " << salary * 0.00 << " twarps.\n";
            cout << "Enter your salary:";
            cin >> salary;
        }
        else if(salary > 5000 && salary <= 15000)
        {
            double tax = (salary - 5000) * 0.10;
            cout << "Your tax is " << tax << " twarps.\n";
            cout << "Enter your salary:";
            cin >> salary;
        }
        else if(salary > 15000 && salary <= 35000)
        {
            double tax = ((salary - (5000 + 10000)) * 0.15) + (5000 * 0.00) + (10000 * 0.10);
            cout << "Your tax is " << tax << " twarps.\n";
            cout << "Enter your salary:";
            cin >> salary;
        }
        else
        {
            double tax = (((salary - (5000 + 10000 + 20000)) * 0.20)) + (5000 * 0.00) + (10000 * 0.10) + (20000 * 0.15);
            cout << "Your tax is " << tax << " twarps.\n";
            cout << "Enter your salary:";
            cin >> salary;
        }
    }
    cout << "Done!\n";
    return 0;
}
