// numstr.cpp --  строковый ввод после числовой
#include <iostream>
int main()
{
    using namespace std;
    cout << "What year was your house built?\n";
    int year;
    cin >> year;
    cin.get();  // чтение символа новой строки(Если убрать данную строку то ввести адрес не получится)
    cout << "What is its street adress?\n";
    char adress[80];
    cin.getline(adress,80);
    cout << "Year built: " << year << endl;
    cout << "Adress : " << adress <<endl;
    cout << "Done!\n";
    return 0;
}
