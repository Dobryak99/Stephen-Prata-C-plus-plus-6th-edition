// insrt1.cpp -- чтение более одной строки
#include <iostream>
int main()
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];
    cout << "Enter your name : \n";
    cin >> name;
    cout << "Enter your favourite dessert: \n";
    cin >> dessert;
    cout << "I have some delicios " << dessert << " for you " << name << endl;
    return 0;
}
