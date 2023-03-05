#include "queue.h"
//#include "queue.cpp"
#include "worker.h"
//#include "worker.cpp"

#include <cstring>

const int SIZE = 5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;              //функция возвращает адрес первого вхождения символа

    Queue<Worker *> lolas(SIZE);
    Worker* wk[SIZE];
    int ct;
    for(ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter The employee category:\n"
        << "w: waiter s: singer "
        << "t: singing waiter q: quit:\n";
        cin >> choice;
        while(strchr("wstq", choice) == NULL)
        {
            cout << "Please enter a w, s, t or q: ";
            cin >> choice;
        }
        if(choice == 'q')
        {
            break;
        }
        switch(choice)
        {
            case 'w':   wk[ct] = new Waiter;
                        break;
            case 's':   wk[ct] = new Singer;
                        break;
            case 't':   wk[ct] = new SingingWaiter;
                        break;
        }
        cin.get();
        wk[ct]->Set();
        lolas.push(wk[ct]);
    }
    cout << "\nHere's your staff: \n";
    for(int i = 0; i < ct; i++)
    {
        cout <<endl;
        lolas.pop(wk[i]);
        wk[i]->Show();
        delete wk[i];
    }
    cout << "Bye!\n";
    return 0;
}
