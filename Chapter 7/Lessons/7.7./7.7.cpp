// arrfun3.cpp --функция работы с масивами и применение const
#include <iostream>
const int Max = 5;
// прототипы функции

int fill_array(double ar[], int limit);
void show_array(const double ar[], int n);
void revalue(double r, double ar[], int n);

int main()
{
    using namespace std;
    double properties[Max];
    int size = fill_array(properties, Max);
    show_array(properties, size);
    if (size > 0)
    {
        cout << "Enter revaluation factor: ";   // ввод коэф переоценки
        double factor;
        while(!(cin >> factor))    // неправильный ввод
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "Bad input; Please enter a number: ";   //повторный запрос на ввод числа
        }
        revalue(factor, properties, size);
        show_array(properties, size);
    }
    cout << "Done!\n";
    return 0;
}
int fill_array(double ar[], int limit)
{
    using namespace std;
    double temp;
    int i;
    for(i = 0; i < limit; i++)
    {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if(!cin)     //не правильный ввод
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (temp < 0)
            break;
        ar[i] = temp;
    }
    return i;
}

// следующая функция может использовать, но не изменять, массив по адресу ar

void show_array(const double ar[], int n)
{
    using namespace std;
    for(int i = 0; i < n; i++)
    {
        cout << "Property #" << (i +1) << ": $";
        cout << ar[i] << endl;
    }
}

//умножаем на r каждый элемент ar[]

void revalue(double r, double ar[], int n)
{
    for(int i = 0; i < n; i++)
        ar[i] *= r;
}
