#include <iostream>
using namespace std;
struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};
// Вариант "А" (из учебника)
void show1(box a);
// Вариант "Б" (из учебника)
void show2(box * pa);
int main()
{
    box number1;
    cout << "First task.\n";
    show1(number1);
    cout << "\nSecond task.\n";
    box number2;
    show2(&number2);
    return 0;
}
void show1(box a)     // для задания "А"
{
    cout << "Enter the \"maker\" -> ";
    cin >> a.maker;
    cout << "Enter the height -> ";
    cin >> a.height;
    cout << "Enter the width -> ";
    cin >> a.width;
    cout << "Enter the length -> ";
    cin >> a.length;
    cout << "Enter the volume -> ";
    cin >> a.volume;
    cout << "\n=======================\n";
    cout << "\"Maker\": " << a.maker << "." << endl;
    cout << "The height: " << a.height << endl;
    cout << "The width: " << a.width << endl;
    cout << "The length: " << a.length << endl;
    cout << "The volume: " << a.volume << endl;
}
void show2(box * pa)   //для задания "Б"
{
    cout << "Enter the \"maker\" -> ";
    cin >> pa -> maker;
    cout << "Enter the height -> ";
    cin >> pa -> height;
    cout << "Enter the width -> ";
    cin >> pa -> width;
    cout << "Enter the length -> ";
    cin >> pa -> length;
    cout << "\n=======================\n";
    cout << "\"Maker\": " << pa -> maker << "." << endl;
    cout << "The height: " << pa -> height << endl;
    cout << "The width: " << pa -> width << endl;
    cout << "The length: " << pa -> length << endl;
    pa -> volume = pa -> height * pa -> width * pa -> length;
    cout << "The volume: " << pa -> volume << endl;
}
