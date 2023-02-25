#include <iostream>
#include <cctype>
#include "10_5.h"
//#include "10_5.cpp"

int main()
{
    using namespace std;
    Stack st;  //   создание пустого стека
    char ch;
    customer po;
    cout << "Please enter A to add a customer.\n"
    <<"P to process a PO, or Q to quit.\n";
    while(cin >> ch && toupper(ch) != 'Q')
    {
        while(cin.get()!= '\n')
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
            case 'a': cout << "Enter customer name: ";
                    cin.get(po.fullname,35);
                    cout << "Enter payment amount: ";
                    cin >> po.payment;
                    if(st.isfull())
                    {
                        cout << "Stack already full\n";
                    }else{
                        st.push(po);
                    }
                    break;
            case 'P':
            case 'p':if(st.isempty())
                    {
                        cout << "Stack already empty\n";
                    }else{
                        st.pop(po);
                        cout << "Customer " << po.fullname << " popped.\n";
                    }
                    break;
        }
        cout << "Please enter A to add a customer.\n"
        <<"P to process a PO, or Q to quit.\n";   
    }
    cout << "Bye!\n";
    return 0;
}
