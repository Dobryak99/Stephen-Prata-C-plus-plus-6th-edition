#include "person.h"
//#include "person.cpp"
#include <cstring>

const int SIZE = 5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;
    Person * pers[SIZE];
    int ct;
    for(ct = 0; ct < SIZE; ct++)
    {
        char ch;
        cout << "\nEnter the person category:\n"
            << "G : Gunclinger P: Pokerplayer "
            << "B: BadDude Q: quit:\n";
            cin >> ch;
            while(strchr("GPBQ", ch) == NULL)
            {
                cout << "Enter G, P, B or Q: ";
                cin >> ch;
            }
            if(ch == 'Q')
            {
                break;
            }
            switch(ch)
            {
                case 'G' :  pers[ct] = new Gunslinger;
                            break;
                case 'P' :  pers[ct] = new PokerPlayer;
                            break;
                case 'B' :  pers[ct] = new BadDude;
                            break;
            }
            cin.get();
            pers[ct] -> Set();
    }

    cout << "\nHere's your team:\n";
    for(int i = 0; i < ct; i++)
    {
        cout << endl;
        pers[i] -> Show();
    }
    for(int i = 0; i < ct; i++)
    {
        delete pers[i];
    }
    cout << "Bye!\n";
    return 0;
}
