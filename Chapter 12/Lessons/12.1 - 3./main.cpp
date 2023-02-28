////strngbad.cpp -- методы класса StrngBad
#include <cstring>
#include "StringBad.hpp"

using std::cout;

//Инициализация статического члена класа
int StringBad::num_strings = 0;

//Методы класса

//Создание StrngBad из С строки
StringBad::StringBad(const char * s)
{
    len = std::strlen(s);           //Установка размера
    str = new char[len + 1];        //выделение памяти
    std::strcpy(str,s);             //инициализация указателя
    num_strings++;                  //счетчик объектов
    cout << num_strings << ": \"" << str << "\" objects created.\n";
}

StringBad::StringBad()
{
    len = 4;
    str = new char[len];
    std::strcpy(str,"C++");
    num_strings++;
    cout << num_strings << ": \"" << str << "\" default objects created.\n";
}

StringBad::~StringBad()             //Необходимый деструктор
{
    cout << "\"" << str << "\" object deleted, ";
    --num_strings;                  //является обязательным
    cout << num_strings << " left\n";
    delete [] str;                  //является обязательным
}

std::ostream & operator<<(std::ostream & os, const StringBad & st)
{
    os << st.str;
    return os;
}
