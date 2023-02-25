#include <iostream>
#include "10.8.h"
//#include "10.8.cpp"

void to_big(std::string & n);
void to_little(std::string & n);
void choose(List &m);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    List st;
    char ch;
    std::string po;

    cout << "\nPlease, enter A to add item,\n"
    << "V to see additional actions with list,\n"
    << "R to reset and S to show list,\n"
    << "Q to quit:";

    while(cin >> ch && toupper(ch) != 'Q')
    {
        while(cin.get() != '\n')
        {
            continue;
        }
        if(!isalpha(ch))
        {
            cout << "\a";
            continue;
        }
        switch(ch)
        {
            case 'A':
            case 'a': cout << "\nEnter what would you add to you shopping list: ";
                    if(st.isfull())
                    {
                        cout << "\nYour list is full.\n";
                    }else{
                        cin >> po;
                        st.add(po);
                    }
                    break;
            case 'V':
            case 'v':choose(st);
                    break;
            case 'R':
            case 'r':st.reset();
                    st.show();
                    break;
            case 'S':
            case 's':st.show();
                    break;
        }
        cout << "\nPlease, enter A to add item,\n"
    << "V to see additional actions with list,\n"
    << "R to reset and S to show list,"
    << " Q to quit:";
    }
    cout << "Bye!\n\n";
    return 0;
}

void to_big(std::string & n)
 {
    int num = n.size();
    for(int i = 0; i < num; i++)
    {
        n[i] = toupper(n[i]);
    }
 }

 void to_little(std::string & n)
 {
    int num = n.size();
    for(int i = 0; i < num; i++)
    {
        n[i] = tolower(n[i]);
    }
 }
 void choose(List & m)
 {
    char choose;
    std::cout << "\nPress B to make capital letters\n"
    << "L to make lowercase letters, Q to return:\n";
    while(std::cin >> choose && toupper(choose) != 'Q')
    {
        switch(choose)
        {
            case 'B':
            case 'b': m.visit(to_big);
                m.show();
                break;
            case 'L':
            case 'l': m.visit(to_little);
                m.show();
                break;
        }
        std::cout << "Q to return:";
    }
 }
 
