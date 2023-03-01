#include "String.h"
#include <cstring>
#include <cctype>

using std::cin;
using std::cout;

int String::num_strings = 0;

int String::HowMany()
{
    return num_strings;
}

String::String(const char * s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str,s);
    num_strings++;
}

String::String()
{
    len = 4;
    str = new char[1];
    str = nullptr;
    num_strings++;
}

String::String(const String & s)
{
    num_strings++;
    len = s.len;
    str = new char(len + 1);
    std::strcpy(str, s.str);
}

String::~String()
{
    --num_strings;
    delete [] str;
}

//присваивание объекта String объекту String
String & String::operator=(const String & s)
{
    if(this == &s)
    {
        return *this;
    }
    delete [] str;
    len = s.len;
    str = new char[len + 1];
    std::strcpy(str, s.str);
    return *this;
}

//присваивание объекта C-строки объекту String
String & String::operator=(const char * s)
{
    delete[] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

//запись и чтение
char & String::operator[](int i)
{
    return str[i];
}

//только чтение
const char & String::operator[](int i) const
{
    return str[i];
}

bool operator<(const String & st1, const String & st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String & st1, const String & st2)
{
    return st1.str > st2.str;
}

bool operator==(const String & st1, const String & st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

ostream & operator<<(ostream & os, const String & s)
{
    os << s.str;
    return os;
}

istream & operator>>(istream & is, String & s)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if(is)
    {
        s = temp;
    }
    while(is && is.get() != '\n')
        continue;
    return is;
}

//новые методы
int String::has(char ch) const
{
    int counter = 0;
    for(int i = 0; i < len; i++)
    {
        if(str[i] == ch)
        {
            counter++;
        }else{
            continue;
        }
    }
    return counter;
}

void String::stringlow()
{
    int length = std::strlen(str);
    for(int i = 0; i < length; i++)
    {
        str[i] = tolower(str[i]);
    }
}

void String::stringup()
{
    int length = std::strlen(str);
    for(int i = 0; i < length; i++)
    {
        str[i] = toupper(str[i]);
    }
}

String String::operator+(const String & s)
{
    String temp;
    delete [] temp.str;

    temp.len = std::strlen(s.str) + std::strlen(this->str);
    temp.str = new char[temp.len + 1];
    std::strcat(std::strcpy(temp.str, this->str), s.str);
    return temp;
}

String operator+(const char * str, const String & s)
{
    String temp;
    delete [] temp.str;

    temp.len = std::strlen(s.str) + std::strlen(str);
    temp.str = new char[temp.len + 1];
    std::strcat(std::strcpy(temp.str, str), s.str);
    return temp;
}


