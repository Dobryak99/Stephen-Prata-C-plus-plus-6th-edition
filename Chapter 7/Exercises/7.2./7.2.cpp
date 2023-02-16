#include <iostream>
using namespace std;
int fill_array(int ar[], int a);
void show_array(const int ar[], int a);
void average(const int ar[], int a);
const int Arsize = 10;
int main()
{
    int score[Arsize];
    int size = fill_array(score, Arsize);
    show_array(score, size);
    average(score, size);
    return 0;
}
int fill_array(int ar[], int a)
{
    int number;
    int i;
    for(i = 0; i < a; i++)
    {
        cout << "Enter score #" << (i + 1) << ":";
        cin >> number;
        if(!cin)   //неправильный ввод
        {
            cin.clear();    //очищаем ввод
            while(cin.get() != '\n')    //до символа конца строки
                continue;
            cout << "Bad input. Input process terminated.\n";
            break; 
        }
        else if(number <= 0)
            break;
        ar[i] = number;
    }
    return i;
}
void show_array(const int ar[], int a)
{
    for(int i = 0; i < a; i++)
    {
        cout << "Score #" << (i + 1) << ":" << ar[i] << endl;
    }
}
void average(const int ar[], int a)
{
    double sum;
    for(int i = 0; i < a; i++)
    {
        sum += ar[i];
    }
    sum = sum / a;
    cout << "the average score is " << sum << endl;
}
