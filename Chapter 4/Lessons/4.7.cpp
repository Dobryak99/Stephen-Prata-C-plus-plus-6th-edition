// strtype1.cpp -- использования класса С++ string
#include <iostream>
#include <string>
int main()
{
    using namespace std;
    char charr1[20];              //создание пустого массива
    char charr2[20] = "yaguar";   // создание инициализированного массива
    string str1;                  // создание пустого объекта строки
    string str2 = "panther";      // создание инициализированнного объекта строки
    cout << "Enter a kind of feline: "; //введите животное из семейства кошачьих
    cin >> charr1;
    cout << "Enter anothe kind of feline: "; //введите еще одно животное из семейства кошачьих
    cin >> str1;
    cout << "Here are some felines: \n";
    cout << charr1 << " " << charr2 << " " << str1 << " " << str2 << endl;
    cout << "The third letter in " << charr2 << " is " << charr2[2] << endl;
    cout << "the third letter in " << str2 << " is " << str2[2] << endl;
    return 0;
}
