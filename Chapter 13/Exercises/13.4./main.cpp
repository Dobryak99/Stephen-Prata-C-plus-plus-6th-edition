#include "port.h"
//#include "port.cpp"
#include <iostream>

const int MAX = 1;
const int LEN = 20;

int main()
{
    Port * p_bottles[MAX];
    char temp_brand[LEN];
    char temp_style[LEN];
    char temp_nickname[LEN];
    int temp_year;
    int temp_bottles;
    for(int i = 0; i < MAX; i++)
    {
        cout << "Enter the name of the brand: ";
        cin.getline(temp_brand, LEN);
        cout << "Enter style(\"tawny\", \"ruby\" or \"vintage\"): ";
        cin.getline(temp_style, LEN);
        if(strcmp(temp_style, "vintage") == 0)
        {
            cout << "Enter number of bottles: ";
            cin >> temp_bottles;
            cout << "Enter nickname: ";
            while(cin.get() != '\n')
                continue;
            cin.getline(temp_nickname,LEN);
            cout << "Enter year of production: ";
            cin >> temp_year;
            p_bottles[i] = new VintagePort(temp_brand, temp_bottles, temp_nickname, temp_year);
        }else{
            cout << "Enter number of bottles: ";
            cin >> temp_bottles;
            p_bottles[i] = new Port(temp_brand, temp_style, temp_bottles);
        }
        while(cin.get() != '\n')
        {
            continue;
        }
    }
    cout << "\nShowing all bottles( using Show() ): \n";
    for(int i = 0; i < MAX; i++)
    {
        p_bottles[i] -> Show();
    }

    cout << "\nShowing all bottles ( using cout ): \n";                     //выводит только тип PORT
    for(int i = 0; i < MAX; i++)
    {
            cout << *(p_bottles[i]) << endl;
    }

    cout << "\nAdding 2 more bottles: \n";
    for(int i = 0; i < MAX; i++)
    {
        cout << "number of bottles before:";
        cout << p_bottles[i] -> BottleCount();
        *(p_bottles[i]) += 2;                       // * необходима для разыменовывания, иначе будет меняться адрес
        cout << endl;
        cout << "number of bottles now:";
        cout << p_bottles[i] -> BottleCount();
        cout << endl;
    }
    
    cout << "\nSubtract 2  bottles: \n";
    for(int i = 0; i < MAX; i++)
    {
        cout << "number of bottles before:";
        cout << p_bottles[i] -> BottleCount();
        cout << endl;
        *(p_bottles[i]) -= 2;                       // * необходима для разыменовывания, иначе будет меняться адрес
        cout << "number of bottles now:";
        cout << p_bottles[i] -> BottleCount();
        cout << endl;
    }

    cout << "Done!\n";
    return 0;
}

