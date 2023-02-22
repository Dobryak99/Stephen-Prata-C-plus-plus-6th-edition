//stacker.cpp -- тестирование класса Stack
#include <iostream>
#include <cctype>
#include "stack.h"

int main()
{
    using namespace std;
    Stack st;  // создание пустого стека
    char ch;
    unsigned long po;
    // А - добавление заказа, Р - обработка заказа, Q - завершение заказа
    cout << "Please enter A to add a purchase order,\n"
    << "P to purchase a PO, ot Q to quit.\n";
    while(cin >> ch && toupper(ch) != 'Q')
    {
        while(cin.get() != '\n')
        {
            continue;
        }
        if(!isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch(ch)
        {
            case 'A':
            case 'a': cout << "Enter a PO number to add: ";
                cin >> po;
                if(st.isfull())
                {
                    cout << "Stack already full\n";
                } else{
                    st.push(po);
                }
                break;
            case 'P':
            case 'p': if(st.isempty())
            {
                cout << "Stack already empty.\n";
            }else{
                st.pop(po);
                cout << "PO #" << po << " popped.\n";
            }
                break;
        }
        cout << "Please enter A to add a purchase order,\n"
        << "P to purchase a PO, ot Q to quit.\n";
    }
    cout << "Bye.\n";
    return 0;
}
