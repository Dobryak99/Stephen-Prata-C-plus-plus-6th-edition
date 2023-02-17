// tempover.cpp -- перегрузка шаблонов
#include <iostream>
template <typename T>           //шаблон А
void ShowArray(T arr[], int n);
template <typename T>           // Шаблон Б
void ShowArray(T *arr[], int n);
struct debts
{
    char name[50];
    double amount;
};
int main()
{
    using namespace std;
    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] = {
        {"Ima Wolfe", 2400.00},
        {"Ura Fox", 1300.00},
        {"Iby Stout", 1800.00}
    };
    double * pd[3];
    //установка указателей на члены amount структур в mr_E
    for(int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;
    cout << "Listing Mr. E's counts of things:\n";
    ShowArray(things, 6); // используется шаблон А
    cout << "Listing Mr. E's debts:\n";
    ShowArray(pd, 3);    // используется шаблон Б
    return 0;
}
template <typename T>
void ShowArray(T arr[], int n)
{
    using namespace std;
    cout << "template A\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}
template <typename T>
void ShowArray(T *arr[], int n)
{
    using namespace std;
    cout << "Temaplte B\n";
    for(int i = 0; i < n; i++)
        cout << *arr[i] << ' ';
    cout << endl;
}

