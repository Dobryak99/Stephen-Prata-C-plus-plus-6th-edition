//stacktem.cpp -- тестирование шаблонного класса стека
#include "stacktm.hpp"
#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;

int main()
{
    Stack<std::string> st;
    char ch;
    std::string po;
    cout << "Please enter A to add a purchase order,\n"
    << "P to process a PO, or Q to quit:\n";
    while(cin >> ch && std::toupper(ch) != 'Q')
    {
        while(cin.get() != '\n')
        {
            continue;
        }
        if(!std::isalpha(ch))
        {
            cout << "\a";
            continue;
        }
        switch(ch)
        {
            case 'A':
            case 'a':   cout << "Enter a PO number to add: ";
                cin >> po;
                if(st.isfull())
                {
                    cout << "Stack is already full.\n";
                }else{
                    st.push(po);
                }
                break;
            case 'P':
            case 'p':   if(st.isempty())
            {
                cout << "Stack is alredy empty.\n";
            }else{
                st.pop(po);
                cout << "PO #" << po << " Popped.\n";
            }
                break;
        }
        cout << "Please enter A to add a purchase order,\n"
        << "P to process a PO, or Q to quit:\n";
    }
    cout << "Bye!\n";
    return 0;
}
