// insrt3.cpp -- чтение более одного слова с помощью get() и get()
#include <iostream>
int main()
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];
    cout << "Enter your name: \n";  //Запрос имени
    cin.get(name,ArSize) .get();    // Читать строку и символ новой строки
    cout << "Enter your favorite dessert: \n";  //Запрос любимого десерта
    cin.get(dessert,ArSize) .get();
    cout << "I have some delicious " << dessert << " for you, " << name << "." << endl;
    return 0;
}
