#include <iostream>
void harmonic(double a, double b);
int main()
{
    using namespace std;
    double number1, number2;
    cout << "Enter numbers.\n";
    cout << "Number 1:";
    cin >> number1;
    cout << "Number 2:";
    cin >> number2;
    while(number1 != 0 && number2 != 0)
    {
        harmonic(number1, number2);
        cout << "Number 1:";
        cin >> number1;
        cout << "Number 2:";
        cin >> number2;
    }
    cout << "The programm finished!!!\n";
    return 0;
}
void harmonic(double a, double b)
{
    using namespace std;
    double average = 2.0 * a * b / (a + b);
    cout << "harmonic mean = " << average << endl;
    cout << "Enter another numbers.\n";
}
