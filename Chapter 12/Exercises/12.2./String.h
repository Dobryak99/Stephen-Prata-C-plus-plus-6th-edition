#ifndef STRING_H_
#define STRING_H_

#include <iostream>
using std::ostream;
using std::istream;

class String
{
    private:
        char * str;
        int len;
        static int num_strings;
        static const int CINLIM = 80;
    public:
        String(const char * s);
        String();
        String(const String & s);
        ~String();
        int length() const {return len;}

        String & operator=(const String & s);
        String & operator=(const char * s);
        char & operator[](int i);
        const char & operator[](int i) const;

        friend bool operator<(const String & st1, const String & st2);
        friend bool operator>(const String & st1, const String & st2);
        friend bool operator==(const String & st1, const String & st2);
        friend ostream & operator<<(ostream & os, const String & s);
        friend istream & operator>>(istream & is, String & s);

        static int HowMany();

        // Новые методы
        int has(char ch) const;                                         //колчичество появления символа в строке
        void stringlow();                                               //преобразование всех букв в нижний регистр
        void stringup();                                                //преобразование всех букв в верний регистр

        String operator+(const String &s);                              //объединение строк
        friend String operator+(const char * str, const String & s);    //объединение строк

};

#endif
