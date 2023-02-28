//string1.h -- исправленное и расширенное объявление строкового класса
#ifndef STRING1_H_
#define STRING1_H_

#include <iostream>

using std::ostream;
using std::istream;

class String
{
private:
    char * str;                         //указатель на строку
    int len;                            //длина строки
    static int num_string;              //количество объектов
    static const int CINLIM = 80;       //предел ввода cin
public:
    //конструкторы и другие методы
    String(const char * s);             //конструктор
    String();                           //конструктор по умолчанию
    String(const String & s);           //конструктор копирования
    ~String();                          //деструктор
    int length() const {return len;}
    
    //методы перегурженных операций
    String & operator=(const String & s);
    String & operator=(const char * s);
    char & operator[](int i);
    const char & operator[](int i) const;
    
    //дружественные функции перегруженных операций
    friend bool operator<(const String & st1, const String & st2);
    friend bool operator>(const String & st1, const String & st2);
    friend bool operator==(const String & st1, const String & st2);
    friend ostream & operator<<(ostream & os, const String & st);
    friend istream & operator>>(istream & is, String & st);
    
    //статическая функция
    static int HowMany();
};

#endif
