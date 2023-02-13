// cinfish.cpp -- нечисловой ввод прекращает выполнение цикла
#include <iostream>
const int Max = 5;
int main()
{
    using namespace std;
    // получение данных
    double fish[Max];
    cout << "Please enter the weights of your fish.\n"
    << "You may enter up to " << Max << " fish <q to terminate>.\n";  // ввод веса пойманных рыб
    cout << "Fish #1: ";
    int i = 0;
    while (i < Max && cin >> fish[i])
    {
        if(++i < Max)
            cout << "Fish #" << i + 1 << ": ";
    }
    // вычесление среднего значения
    double total = 0.0;
    for (int j = 0; j < i; j++)
        total += fish[j];
    //вывод результатов
    if (i == 0)
        cout << "No fish.\n";
    else cout << total / i << " = average weight of " << i << " fish.\n";
    cout << "Done!.\n";
    return 0;
}
