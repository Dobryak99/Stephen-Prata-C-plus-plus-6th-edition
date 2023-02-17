// strquote.cpp -- различные решения
#include <iostream>
#include <string>
using namespace std;
string version1(const string & s1, const string & s2);
const string & version2(string & s1, const string & s2);  //имеет побочный эффект
const string & version3(string & s1, const string & s2);  //неудачное решение
int main()
{
    string input;
    string copy;
    string result;
    cout << "Enter a string: ";
    getline(cin, input);  // ввод строки
    copy = input;
    cout << "Yout string as entered: " << input << endl;
    result = version1(input, "***");   // отображение введеной строки
    cout << "Yor string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;
    result = version2(input, "###");
    cout << "Yor string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;
    input = copy;
    result = version3(input, "@@@");
    cout << "Yor string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;
    return 0;
}
string version1(const string & s1, const string & s2)
{
    string temp;
    temp = s2 + s1 + s2;
    return temp;
}
const string & version2(string & s1, const string & s2)   //имеет побочный эффект
{
    s1 = s2 + s1 + s2;  //возврат ссылки, переданной функции, безопасен
    return s1;
}
const string & version3(string & s1, const string & s2)   //неудачное решение
{
    string temp;
    temp = s2 + s1 + s2;   // возврат ссылки на локальную переменную небезопасен
    return temp;
}
