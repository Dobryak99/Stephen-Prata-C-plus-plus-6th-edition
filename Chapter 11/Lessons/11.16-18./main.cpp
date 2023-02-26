//stone.cpp -- определенные пользователем преобразования
#include <iostream>
#include "Stonewt.hpp"
using std::cout;


void display(const Stonewt & st, int n);


int main()
{
    Stonewt incognito = 275;   //использование конструктора для инициализации
    Stonewt wolfe(285.7);      //тот же, что и Stonewt wolfe = 285.7
    Stonewt tatf(21, 8);
    
    cout << "The celebrity weighed: ";
    incognito.show_stn();
    
    cout << "The detective weighed: ";
    wolfe.show_stn();
    
    cout << "The president weighed: ";
    tatf.show_lbs();
    
    incognito = 276.8;         //использование конструктора для преобразования
    tatf = 325;
    
    cout << "After dinner, the celebrity weighed: ";
    incognito.show_stn();
    
    cout << "After dinner,  the president weighed: ";
    tatf.show_lbs();
    
    display(tatf,2);
    
    cout << "The wrestler weighed even more.\n";
    display(422,2);
    cout << "No stone left unearned\n";
    return 0;
}

void display(const Stonewt & st, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "Wow! ";
        st.show_stn();
    }
}

