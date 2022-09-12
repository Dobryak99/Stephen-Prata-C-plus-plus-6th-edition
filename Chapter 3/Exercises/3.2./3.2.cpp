#include <iostream>
#include <cmath>
int main()
{
    using namespace std;
    int feet, inch, pound;
    const int inch_per_feet = 12;
    const double meter_per_inch = 0.0254;
    const double kg_per_pound = 2.2;
    cout << "Enter your height in feet and inches: ";
    cin >> feet;
    cin >> inch;
    cout << "Enter your weight: ";
    cin >> pound;
    int height = (feet * inch_per_feet) + inch;
    double height2 = height * meter_per_inch;
    double weight = pound / kg_per_pound;
    double BMI = weight / pow(height2, 2);
    cout << "Your body mass index is " << BMI;
    return 0;
}
