#include <iostream>
#include <cstring>
#include "bankacc.h"

Account::Account(const std::string & co_name, const char *account, double balance)
{
    name = co_name;
    pline = new char[strlen(account) + 1];
    strcpy(pline, account);
    bal = balance;
}

void Account::show() const
{
    std::cout << "Name of the company: " << name << ".\n"
    << "Account №: " << pline << ".\n"
    << "Balance: $" << bal << ".\n";
}

void Account::add(double number)
{
    bal += number;
    std::cout << "Your balance now is: " << bal << ".\n";
}

void Account::transfer(double number)
{
    if(bal <= 0)
    {
        std::cout << "You don't have enough money.Bye!\n";
    }else if(number > bal)
    {
        std::cout << "You don't have enough money.Bye!\n";
    }else{
        bal -= number;
        std::cout << "Your balance now is: " << bal << ".\n";
    }
}

void Account::Del()
{
    delete [] pline;
}
