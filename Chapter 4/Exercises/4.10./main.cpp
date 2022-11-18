#include <iostream>
#include <array>
int main()
{
    using namespace std;
    array <double,3> ad;
    cout << "Enter the resul of the first runner: ";
    cin >> ad[0];
    cout << "Enter the resul of the second runner: ";
    cin >> ad[1];
    cout << "Enter the resul of the third runner: ";
    cin >> ad[2];
    cout << "The results of the first run: " << ad[0] << endl;
    cout << "The results of the second run: " << ad[1] << endl;
    cout << "The results of the third run: " << ad[2] << endl;
    cout << "Average: " << (ad[0] + ad[1] + ad[2]) / 3 << endl;
    return 0;
}
