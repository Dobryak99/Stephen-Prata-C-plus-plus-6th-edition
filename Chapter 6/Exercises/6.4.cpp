#include <iostream>
using namespace std;
const int Size = 50;
const int arr = 5;
void menu();
struct BOP
{
    char fullname[Size];
    char title[Size];
    char bopname[Size];
    int preference;
};
int main()
{
    BOP names[arr] =
    {
        {"Ivan Ivanovich", "CEO","CERJ",2},
        {"Vadim Sergeevich", "Owner", "BOSS", 0},
        {"Sergei Olegovich", "Senior developer", "CooL Guy", 1},
        {"Olga Viktorovna", "middle developer", "Bookworm", 0},
        {"Artem Igorevich", "junior developer", "\"How to do it\"", 2},
    };
    char choice;
    menu();
    cout << "Enter your choice:";
    while(choice != 'q' && cin >> choice)
    {
        switch(choice)
        {
            case 'a':
            {
                for(int i = 0; i < arr; i++)
                    cout << names[i].fullname << endl;
                cout << "\nNext choice:";
                break;
            }
            case 'b':
            {
                for(int j = 0 ; j < arr; j++)
                    cout << names[j].title << endl;
                cout << "\nNext choice:";
                break;
            }
            case 'c':
            {
                for(int k = 0; k < arr; k++)
                    cout << names[k].bopname << endl;
                cout << "\nNext choice:";
                break;
            }
            case 'd':
            {
                for(int i = 0; i < arr; i++)
                {
                    if(names[i].preference == 0)
                        cout << names[i].fullname << endl;
                    else if(names[i].preference == 1)
                        cout << names[i].title << endl;
                    else if(names[i].preference == 2)
                        cout << names[i].bopname << endl;
                }
                cout << "\nNext choice:";
                break;
            }
            case 'q':
            {
                cout << "\nBye!\n";
            }
        }
    }
    return 0;
}
void menu()
{
    cout << "Benevolent Order of programmers Report\n"
    << "a. display by name      b. display by title\n"
    << "c. display by bopname   d. display by preference\n"
    << "q. quit\n";
};
