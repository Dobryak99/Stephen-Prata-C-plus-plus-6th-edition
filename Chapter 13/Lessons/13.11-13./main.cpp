
//usebrass3.cpp -- полиморфный пример с использованием абстрактного базового класса

#include "bank.hpp"
#include <iostream>

const int CLIENTS = 4;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    
    AcctABC * p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;
    
    for(int i = 0; i < CLIENTS; i++)
    {
        cout << "Enter client's name: ";
        getline(cin,temp);
        cout << "Enter clients account number: ";
        cin >> tempnum;
        cout << "Enter opening balance: ";
        cin >> tempbal;
        cout << "Enter 1 for Brass Account or"
        << " 2 for BrassPlus Account: ";
        while(cin >> kind && (kind != '1' && kind != '2'))
        {
            cout << "Enter 1 or 2: ";
        }
        if(kind == '1')
        {
            p_clients[i] = new Brass(temp,tempnum,tempbal);
        }else{
            double tmax, trate;
            cout << "Enter the overdraft limit: $";
            cin >> tmax;
            cout << "Enter the interrest rate: ";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum,tempbal,tmax,trate);
        }
        while(cin.get() != '\n')
        {
            continue;
        }
    }
    cout << endl;
    for(int i = 0; i < CLIENTS; i++)
    {
        p_clients[i] -> ViewAcct();
        cout << endl;
    }
    for(int i =0; i < CLIENTS; i++)
    {
        delete p_clients[i];
    }
    cout << "Done!\n";
    return 0;
}
