//acctabc.cpp -- методы класса банковских счетов

#include <iostream>
#include "bank.hpp"

using std::cout;
using std::ios_base;
using std::endl;
using std:: string;

//Абстрактный базовый класс (АБК)

AcctABC::AcctABC(const string & s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}

void AcctABC::Deposit(double amt)
{
    if(amt < 0)
    {
        cout << "Negotive deposit not allowed. "
        << "Deposit is canceled.\n";
    }else{
        balance += amt;
    }
}

void AcctABC::Withdraw(double amt)
{
    balance -= amt;
}

//Защищенные методы для форматирования

AcctABC::Formatting AcctABC::SetFormat() const
{
    //установка формата в ###.##
    Formatting f;
    f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}

void AcctABC::Restore(Formatting & f) const
{
    cout.setf(f.flag, ios_base::floatfield);
    cout.precision(f.pr);
}

//методы Brass

void Brass::Withdraw(double amt)
{
    if(amt < 0)
    {
        cout << "Withdrawal amount must be positive; "
        << "Withdrawal canceled.\n";
    }else if(amt <= Balance())
    {
        AcctABC::Withdraw(amt);
    }else{
        cout << "Withdarwal amount of $" << amt << " exceeds yor balance.\n"
        << "Withdrawal canceled.\n";
    }
}

void Brass::ViewAcct() const
{
    Formatting f = SetFormat();
    cout << "Brass Client: " << FullName() << endl;
    cout << "Account number: " << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    Restore(f);
}

//Методы BrassPlus

BrassPlus::BrassPlus(const string & s, long an, double bal, double ml, double r) : AcctABC(s, an, bal)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r) : AcctABC(ba) //используется неявный констуктор копирования
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct() const
{
    Formatting f = SetFormat();
    cout << "BrassPlus Client: " << FullName() << endl;
    cout << "Account number: " << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed Bank: " << owesBank << endl;
    cout.precision(3);
    cout << "Loan rate: " << rate << "%\n";
    Restore(f);
}

void BrassPlus::Withdraw(double amt)
{
    Formatting f = SetFormat();
    double bal = Balance();
    if(amt <= bal)
    {
        AcctABC::Withdraw(amt);
    }else if(amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        AcctABC::Withdraw(amt);
    }else{
        cout << "Credit limit exceeded. Transaction canceled.\n";
    }
    Restore(f);
}

