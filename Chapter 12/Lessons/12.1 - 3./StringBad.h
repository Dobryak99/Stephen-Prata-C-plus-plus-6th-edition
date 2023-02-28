//strngbad.h -- несовершенное определение класса строки
#ifndef STRINGBAD_H_
#define STRINGBAD_H_
#include <iostream>

class StringBad
{
private:
    char * str;
    int len;
    static int num_strings;
public:
    StringBad(const char * s);
    StringBad();
    ~StringBad();
    
    //Дружественная функция
    friend std::ostream & operator<<(std::ostream & os, const StringBad & st);
};


#endif
