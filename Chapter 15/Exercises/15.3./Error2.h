#ifndef ERROR2_H_
#define ERROR2_H_

#include <iostream>
#include <string>
#include <stdexcept>

class bad_hmean : public std::invalid_argument
{
    private:
        double hv1;
        double hv2;
    public:
        explicit bad_hmean(const std::string & what_arg, double val1 = 0.0, double val2 = 0.0 ) :  std::invalid_argument(what_arg), hv1(val1), hv2(val2) {}
        void show() const;
};

inline void bad_hmean::show() const
{
    std::cout << "Function Hmean() has value 1 = " << hv1 << ", value 2 = " << hv2 << std::endl;
}

class bad_gmean : public std::domain_error
{
    private:
        double gv1;
        double gv2;
    public:
        explicit bad_gmean(const std::string & what_arg, double val1, double val2) : std::domain_error(what_arg), gv1(val1), gv2(val2) {}
        void show() const;
};

inline void bad_gmean::show() const
{
    std::cout << "\nFunction Gmean() has value 1 = " << gv1 << ", value 2 = " << gv2 << std::endl;
}

#endif
