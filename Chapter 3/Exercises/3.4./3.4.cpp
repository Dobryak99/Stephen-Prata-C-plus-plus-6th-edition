#include <iostream>
int main()
{
    using namespace std;
    const int sec_to_days = 86400;
    const int sec_to_hr = 3600;
    const int sec_to_min = 60;
    long second;
    cout << "Enter the number of seconds: ";
    cin >> second;
    // переводим секунды в дни
    long day = second / sec_to_days;
    // переводим секунды в часы
    long hour = (second - (day * sec_to_days)) / sec_to_hr;
    //переводим секунды в минуты
    long min = (second - ((day * sec_to_days) + (hour * sec_to_hr))) / sec_to_min;
    //вычесляем остаток секунд
    long sec = (second - ((day * sec_to_days) + (hour * sec_to_hr) + (min * sec_to_min)));
    cout << second << " seconds = " << day << " days, " << hour << " hours, " << min << " minutes, " << sec << " seconds." << endl;
    return 0;
}
