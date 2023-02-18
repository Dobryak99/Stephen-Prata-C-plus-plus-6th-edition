#include <iostream>
using namespace std;

template <typename T>
void ShowArray(T arr[], int n);

template <typename T>
void ShowArray(T * arr[], int n);

struct debt
{
    char name[50];
    double amount;
};

int main()
{
    int things[6] = {13,31,301,310,130};
    struct debt mr_E[3] = 
    {
        {"Ima Wolfe", 2400.00},
        {"Ura Foxe", 1300.00},
        {"Iby Stout", 1800.00},
    };

    double * pd[3];
        for(int i = 0; i < 3; i++)
        {
            pd[i] = &mr_E[i].amount;
        }
    cout << "Listing Mr. E's sum of things:\n";
    ShowArray(things, 6);
    cout << "Listing Mr. E's sum debts:\n";
    ShowArray(pd, 3);
    return 0;
}

template <typename T>
void ShowArray(T arr[], int n)
{
    cout << "Template A\n";
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    cout << sum << endl;
}

template <typename T>
void ShowArray(T * arr[], int n)
{
    cout << "Template B\n";
    double sum = 0.00;
    for(int i = 0; i < n; i++)
    {
        sum += *arr[i];
    }
    cout << sum <<  endl;
}
