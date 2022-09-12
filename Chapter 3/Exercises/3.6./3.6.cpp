#include <iostream>
int main()
{
    using namespace std;
    int km, litres;
    cout << "Enter the volume of used gas:";
    cin >> litres;
    cout << "Enter the passed distance:";
    cin >> km;
    double lit_per_km = (double(litres) / double(km)) * 100;
    cout << "The consumption per 100 kilometers is " << lit_per_km << endl;
    return 0;
}
