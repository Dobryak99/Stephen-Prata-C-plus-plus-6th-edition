#ifndef BANKACC_H_
#define BANKACC_H_

#include <string>

class Account
{
    private:
        std::string name;
        char * pline;
        double bal;
    public:
        Account(const std::string & co_name, const char *account, double balance);
        void show() const;
        void add(double number);
        void transfer(double number);
        void Del();
};

#endif
