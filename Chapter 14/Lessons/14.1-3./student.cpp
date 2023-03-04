
//student.cpp -- класс Student, использующий включение
#include "student.hpp"

using std::ostream;
using std::endl;
using std::istream;
using std::string;

//Открытые методы
double Student::Average() const
{
    if(scores.size() > 0)
    {
        return scores.sum() / scores.size();
    }else{
        return 0;
    }
}

const string & Student::Name() const
{
    return name;
}
double & Student::operator[](int i)
{
    return scores[i];                               //использует valarray<double>:operator[]()
}
double Student::operator[](int i) const
{
    return scores[i];
}

//Закрытые методы
ostream & Student::arr_out(ostream & os) const
{
    int i;
    int lim = scores.size();
    if(lim > 0)
    {
        for(i = 0; i < lim; i++)
        {
            os << scores[i] << " ";
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
    is >> stu.name;
    return is;
}

// Используют версию getline(istream &, const string &) из класса string

istream & getline(istream & is, Student & stu)
{
    getline(is, stu.name);
    return is;
}

//// Используют версию operator<<() из класса string

ostream & operator<<(ostream & os, const Student & stu)
{
    os << "Scores for " << stu.name << ":\n";
    stu.arr_out(os);                                    //использование закрытого метода для scores
    return os;
}
