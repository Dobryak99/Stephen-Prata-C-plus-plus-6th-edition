#include <iostream>
using namespace std;
double add(double a, double b);
double subtraction(double a, double b);
double calculate(double a, double b, double (*pf)(double , double ));
int main()
{
    double number1, number2;
    cout << "Enter two numbers(q to quit): ";
    while(cin >> number1 >> number2)
    {
        cout << "First function(+): ";
        cout << calculate(number1, number2, add);
        cout << endl;
        cout << "Second function(-): ";
        cout << calculate(number1, number2, subtraction);
        cout << endl;
        cout << "Enter another two numbers(q to quit): "; 
    }
    cout << "Bye!\n";
    return 0;
}
double add(double a, double b)
{
    return a + b;
}
double subtraction(double a, double b)
{
    return a - b;
}
double calculate(double a, double b , double (*pf)(double , double ))
{
    return (*pf)(a,b);
}
