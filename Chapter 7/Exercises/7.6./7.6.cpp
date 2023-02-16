#include <iostream>
int Fill_array(double arr[], double a);
void Show_array(const double arr[], int a);
void Reverse_array(double arr[], int a);
const int Size = 10;
int main()
{
    using namespace std;
    double numbers[Size];
    int realsize = Fill_array(numbers, Size);
    cout << endl;
    Show_array(numbers, realsize);
    cout << endl;
    Reverse_array(numbers, realsize);
    Show_array(numbers, realsize);
    return 0;
}
int Fill_array(double arr[], double a)
{
    using namespace std;
    int i;
    double integer;
    for(i = 0; i < a; i++)
    {
        cout << "Enter " << i + 1 << " value:";
        cin >> integer;
        if(!cin)
        {
            cin.clear();
            cout << "Bad input. Input process terminated.\n";
            break;
        }
        else
        arr[i] = integer;
    }
    return i;
}
void Show_array(const double arr[], int a)
{
    using namespace std;
    for(int i = 0; i < a; i ++)
    {
        cout <<"The value of the " << i + 1 << " element is " <<  arr[i] << endl;
    }
}
void Reverse_array(double arr[], int a)
{
    for(int i = 0; i < a/2; i++)
    {
            int D = arr[i];
            arr[i] = arr[a - i - 1];
            arr[a - i -  1] = D;
    }
}
