// arrobj.cpp --функции с объектами array
#include <iostream>
#include <array>
#include <string>

// константные данные

const int Seasons = 4;
const std::array<std::string,Seasons> Shames = {"Spring", "Summer", "Fall", "Winter"};

// функция для изменения объекта array

void fill (std::array<double, Seasons> * pa);

// функция использующая объект array, но не изменяющая его

void show(std::array<double, Seasons> da);

int main()
{
    std::array<double, Seasons> expenses;
    fill(&expenses);
    show(expenses);
    return 0;
}

void fill(std::array<double, Seasons> *pa)
{
    using namespace std;
    for(int i = 0; i < Seasons; i++)
    {
        cout << "Enter " << Shames[i] << " expenses: ";  // ввод расходов по временам года
        cin >> (*pa)[i];
    }
}

void show(std::array<double, Seasons> da)
{
    using namespace std;
    double total = 0.0;
    cout << "\nEXPENSES:\n";
    for(int i = 0; i < Seasons; i++)
    {
        cout << Shames[i] << ": $" << da[i] << endl;
        total += da[i];
    }
    cout << "Total expenses: $" << total << endl;
}
