#include <iostream>
int main()
{
    using namespace std;
    double degrees, minute, second;
    const double min_to_decimal = 60;
    const double sec_to_decimal = 3600;
    cout << "Enter a latitude in degrees, minutes and seconds" << endl;
    cout << "First, enter the degrees:";
    cin >> degrees;
    cout << "Next, enter the minutes of arc:";
    cin >> minute;
    cout << "finnaly, enter the seconds of arc:";
    cin >> second;
    double min_dec = minute / min_to_decimal;
    double sec_dec = second / sec_to_decimal;
    double decimal = degrees + min_dec + sec_dec;
    cout << degrees << " degrees, " << minute << " minutes, " << second << " seconds = "
    << decimal << " degrees.";
    return 0;
}
