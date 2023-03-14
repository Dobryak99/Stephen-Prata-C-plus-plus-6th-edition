//strout.cpp -- внутреннее форматирование (вывод)
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    using namespace std;
    ostringstream outstr;               //управляет встроенным потоком
    string hdisk;
    cout << "What's the name of your hard disk? ";
    getline(cin, hdisk);
    int cap;
    cout << "What's its capacity in GB? ";
    cin >> cap;
    outstr << "The hard disk " << hdisk << " has capacity of " << cap << " gigabytes.\n";
    string result = outstr.str();       // сохранение результата
    cout << result;
    return 0;
}
