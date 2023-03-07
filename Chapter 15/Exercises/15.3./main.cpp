#include <iostream>
#include <cmath>
#include <exception> // для tipeid
#include "Error2.h"

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x,y,z;
    cout << "Enter two numbers: ";
    while(cin >> x >> y)
    {
        try
        {
            z = hmean(x,y);
            cout << "Harmonic mean of " << x << ", " << y << " is " << z << endl;
            cout << "Geometric mean of " << x << ", " << y << " is " << gmean(x,y) << endl;
            cout << "Enter next two numbers <q to quit>: ";
        }
        catch( std::logic_error & le)
        {
            if(typeid(bad_hmean) ==  typeid(le))
            {
                bad_hmean & temp = dynamic_cast<bad_hmean &>(le);
                temp.show();
                cout << temp.what() << endl;
                break;
            }else if(typeid(bad_gmean) == typeid(le))
            {
                bad_gmean & temp = dynamic_cast<bad_gmean &>(le);
                temp.show();
                cout << temp.what() << endl;
                cout << "Sorry, you dont get to play any more.\n";
                break;
            }
        }
    }
    cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b)
{
    if(a == -b)
    {
        throw bad_hmean("Error hmean(). Invalid arguments: a = -b", a, b);
    }
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if(a < 0 || b < 0)
    {
        throw bad_gmean("Error gmean(). Arguments should be >= 0", a, b);
    }
    return std::sqrt(a * b);
}
