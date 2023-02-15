// protos.cpp -- использование прототипов и вызовы функций
#include <iostream>
void cheers(int);    //  прототип: нет знаения возврата
double cube(double x);  //прототип: возвращает double
int main()
{
    using namespace std;
    cheers(5);   //вызов функции
    cout << "Give me a number: ";
    double side;
    cin >> side;
    double volume = cube(side);   //вызов функции
    cout << "A " << side << "-foot cube has a volume of ";
    cout << volume << " cubic feet.\n";
    return 0;
}
void cheers(int a)
{
    using namespace std;
    for(int i = 0;i < a; i++)
        cout << "Cheers! ";
    cout << endl;
}
double cube(double a)
{
    return a * a * a;
}
