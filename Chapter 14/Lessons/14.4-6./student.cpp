//studenti.cpp -- класс Student, использующий закрытое наследование
#include "student.hpp"

using std::ostream;
using std::endl;
using std::istream;
using std::string;

//Открытые методы
double Student::Average() const
{
    if(ArrayDb::size() > 0)
    {
        return ArrayDb::sum() / ArrayDb::size();
    }else{
        return 0;
    }
}

const string & Student::Name() const
{
    return (const string& ) *this;
}
double & Student::operator[](int i)
{
    return ArrayDb::operator[](i);                               //использует ArrayDb:operator[]()
}
double Student::operator[](int i) const
{
    return ArrayDb::operator[](i);
}

//Закрытые методы
ostream & Student::arr_out(ostream & os) const
{
    int i;
    int lim = ArrayDb::size();
    if(lim > 0)
    {
        for(i = 0; i < lim; i++)
        {
            os << ArrayDb::operator[](i) << " ";
            if(i % 5 == 4)
            {
                os << endl;
            }
        }
        if(i % 5 != 0)
        {
            os << endl;
        }
    }else{
        os << " empty array ";
    }
    return os;
}

//Друзья
// Используют версию operator>>() из класса string

istream & operator>>(istream & is, Student & stu)
{
    is >> (std::string & ) stu;
    return is;
}

// Используют версию getline(istream &, const string &) из класса string

istream & getline(istream & is, Student & stu)
{
    getline(is, (std::string &)stu);
    return is;
}

//// Используют версию operator<<() из класса string

ostream & operator<<(ostream & os, const Student & stu)
{
    os << "Scores for " << (const std::string &)stu << ":\n";
    stu.arr_out(os);                                    //использование закрытого метода для scores
    return os;
}
