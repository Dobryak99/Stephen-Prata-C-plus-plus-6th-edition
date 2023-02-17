#include <iostream>
using namespace std;
int counter = 0;

void show(const char * str, int number = 0);

int main()
{
    const char * pt = "I love you";
    show(pt);
    cout << "Enter number: ";
    int num;
    cin >> num;
    show(pt, num);
    cout << "Enter another number: ";
    cin >> num;
    show(pt, num);
    return 0;
}

void show(const char * str, int number)
{
    counter++;
    if(number != 0)
    {
        for(int i = 0; i < counter; i++)
        {
            cout << str << endl;
        }
    }else{
        cout << str << endl;
    }
}
