#include <iostream>
const int Max = 5;

double* fill_array(double *begin, double *end); //функция возвращает указатель на последний элемент массива
void show_array (double *begin, double *end);
void revalue(double, double *begin, double *end);

int main()
{
    using namespace std;
    double properties[Max];
    
    double *end = fill_array(properties, properties+Max); // название массива=указатель на первый элемент, название+число = элемент массива[число], находим последний эллемент массива и присваеваем адрес указателю end
    show_array(properties, end); // теперь можно смело пользоваться указателем на первый и последний элемент
    if ((end - properties) > 0) // при отнимании результат - целочисленное значение = количеству єлементов в массиве(Результат вычитания двух указателей - это количество элементов между ними.)
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor))    // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; Please enter a number: ";
        }
        revalue (factor, properties, end);
        show_array(properties, end);
    }
    cout << "Done.\n";
    return 0;
}

double* fill_array(double *begin, double *end)
{
    using namespace std;
    double temp;
    double *pt; // создаем временный указатель
    int i = 1;
    for (pt = begin; pt != end; pt++, i++) // присваиваем ему начало массива, цикл до последнего элемента, увеличение указателя на 1 = перемещение на следующий элемент массива
    {
        cout << "Enter value #" << i << ": ";
        cin >> temp;
        if (!cin)    // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (temp < 0)
            break;
        *pt = temp; // разыменовываем указатель и присваеваем ему значение
    }
    return pt; // возвращаем указатель, который остановился на последнем возможном элементе
}

void show_array(double *begin, double *end)
{
    using namespace std;
    double *pt;
    int i = 1;
    for (pt = begin; pt != end; pt++, i++)
    {
        cout << "Property #" << i << ": $";
        cout << *pt << endl;
    }
}

void revalue(double r, double *begin, double *end)
{
    double *pt;
    for (pt = begin; pt != end; pt++)
        *pt *= r;
}
