//brass.cpp -- методы классов банковских счетов
#include "brass.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

//для целей форматирования
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

//методы Brass
Brass::Brass(const string & s, long an, double bal)
{
    fullname = s;
    acctNum = an;
    balance = bal;
}

void Brass::Deposit(double amt)
{
    if(amt < 0)
    {
        cout << "Negative deposit not allowed; "
        <<"deposit is canceled.\n";
    }else{
        balance += amt;
    }
}

void Brass::Withdraw(double amt)
{
    //установка формата ###.##
    format initialState = setFormat();
    precis prec = cout.precision(2);
    
    if(amt < 0)
    {
        cout << "Withdraw amount must be positive; "
        << "Withdraw canceled.\n";
    }else if(amt <= balance)
    {
        balance -= amt;
    }else{
        cout << "Withdraw amount of $" << amt << " exceeds your balance.\n"
        <<"Withdraw canceled.\n";
    }
    restore(initialState, prec);
}

double Brass::Balance() const
{
    return balance;
}

void Brass::ViewAcct() const
{
    //установка формата ###.##
    format initialState = setFormat();
    precis prec = cout.precision(2);
    
    cout << "Client: " << fullname << endl;
    cout << "Account number: " << acctNum << endl;
    cout << "Balance: $" << balance << endl;
    restore(initialState, prec);
}


//методы BrassPlus

BrassPlus::BrassPlus(const string & s, long an, double bal, double m1, double r) : Brass(s,an,bal)
{
    maxLoan = m1;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double m1, double r) : Brass(ba) //использует неявный конструктор копирования
{
    maxLoan = m1;
    owesBank = 0.0;
    rate = r;
}

//переопределение реализации метода ViewAcct()

void BrassPlus::ViewAcct() const
{
    //установка формата ###.##
    format initialState = setFormat();
    precis prec = cout.precision(2);
    
    Brass::ViewAcct();               //отображение базовой части
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.precision(3);              //формат ###.###
    cout << "Loan Rate: " << 100 * rate << "%\n";
    restore(initialState, prec);
}

//переопределение реализации метода Withdraw()

void BrassPlus::Withdraw(double amt)
{
    //установка формата ###.##
    format initialState = setFormat();
    precis prec = cout.precision(2);
    
    double bal = Balance();
    if(amt <= bal)
    {
        Brass::Withdraw(amt);
    }else if(amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;       //аванс банку
        cout << "Finance charge: $" << advance * rate << endl;  //долг банку
        Deposit(advance);
        Brass::Withdraw(amt);
    }else{
        cout << "Credit limit exceeded. Transaction cancelled.\n";
    }
    restore(initialState, prec);
}

format setFormat()
{
    //установка формата ###.##
    return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}
