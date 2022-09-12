//  string.cpp -- сохранение строк в массиве
#include <iostream>
#include <cstring>  //  для функции strlen()
int main()
{
    using namespace std;
    const int Size = 15;           // вводим символическую константу для дальнейшего размера массива
    char name1 [Size];             //Пустой массив
    char name2[Size] = "C++owboy"; //инициализация массива
    cout << "Howdy! I'm " << name2;
    cout << "! What is your name?\n";
    cin >> name1;
    cout << "Well , " << name1 << ", your name has ";
    cout << strlen(name1) << " letters and is stored \n";
    cout << "in an array of " << sizeof (name1) << " bytes.\n";
    cout << "Your initial is " << name1[0] << ".\n";
    name2[3] = '\0';           // установка нулевого символа
    cout << "Here are the first 3 characters of my name: " << name2 << endl;
    return 0;
}
