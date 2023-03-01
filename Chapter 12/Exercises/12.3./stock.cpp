#include "stock.h"
#include <iostream>

Stock::Stock()
{
    company = new char[1];
    company[0] = '\0';
    shares = 0;
    share_val = 0;
    total_val = 0;
}

Stock::Stock(const char * co, long n, double pr)
{
    int length = std::strlen(co);
    company = new char[length + 1];
    std::strcpy(company, co);
    if(n < 0)
    {
        std::cout << "Number of shares can't be negative; "
        << company << " shares set to 0.\n";
        shares = 0;
    }else{
        shares = n;
    }
    share_val = pr;
    set_tot();
}
//констурктор копирования
Stock::Stock(const Stock & s)
{
    int length = std::strlen(s.company);
    company = new char[length + 1];
    std::strcpy(company, s.company);
    shares = s.shares;
    share_val = s.share_val;
    set_tot();
}


//Оператор присваивания
Stock & Stock::operator=(const Stock & s)
{
    if(this == &s)
    {
        return *this;
    }
    delete [] company;
    int length = std::strlen(s.company);
    company = new char[length + 1];
    std::strcpy(company, s.company);
    shares = s.shares;
    share_val = s.share_val;
    set_tot();
    return *this;
}

Stock::~Stock()
{
    delete [] company;
}

void Stock::buy(long num, double price)
{
    if(num < 0)
    {
        std::cout << "Number of shares can't be negative. "
        << "Transaction is aborted.\n";
    }else{
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    if(num < 0)
    {
        std::cout << "Number of shares can't be negative. "
        << "Transaction is aborted.\n";
    }else if(num > shares)
    {
        std::cout << "You can't sell more than you have! "
        << "Transaction is aborted.\n";
    }else{
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

const Stock & Stock::topval(const Stock & s) const{
    if(s.total_val > total_val)
    {
        return s;
    }else{
        return *this;
    }
}

std::ostream & operator<<(std::ostream & os, const Stock & s)
{
    os << "Company: " << s.company << "\n"
    << "Shares: " << s.shares << '\n';
    os << "Share price: $" << s.share_val << "\n";
    os << "Total worth: $" << s.total_val << '\n';
    return os;
}


