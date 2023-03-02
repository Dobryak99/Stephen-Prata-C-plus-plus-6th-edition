//dma.cpp -- методы классов с динамическим выделением памяти

#include "dma.hpp"
#include <cstring>


//Методы baseDMA

baseDMA::baseDMA(const char * l, int r)
{
    label = new char[std::strlen(l) + 1];                   //выделение памяти для копирования
    std::strcpy(label, l);                                  //копирование L в LABEL
    rating = r;
}

baseDMA::baseDMA(const baseDMA & rs)
{
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label,rs.label);
    rating = rs.rating;
}

baseDMA::~baseDMA()
{
    delete [] label;
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    if(this == &rs)
    {
        return *this;
    }
    delete [] label;                                        //освобождение предыдущей памяти
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return * this;
}

std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
    os << "Label: " << rs.label << std::endl;               //название
    os << "Rating: " << rs.rating << std::endl;             //рейтинг
    return os;
}

//Методы lacksDMA

lacksDMA::lacksDMA(const char * c, const char * l, int r) : baseDMA(l,r)
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const baseDMA & rs) : baseDMA(rs)
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & rs)
{
    os << (const baseDMA &)rs;                                      //приведение типа
    os << "Color: " << rs.color << std::endl;
    return os;
}

//Методы hasDMA

hasDMA::hasDMA(const char * s, const char * l, int r) : baseDMA(l,r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style,s);
}

hasDMA::hasDMA(const char * s, const baseDMA &rs) : baseDMA(rs)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style,s);
}

hasDMA::hasDMA(const hasDMA & rs) : baseDMA(rs) //вызывает констуктор копирования базового класса
{
    style = new char[std::strlen(rs.style) + 1];
    std::strcpy(style, rs.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & rs)
{
    if(this == &rs)
    {
        return *this;
    }
    baseDMA::operator= (rs);                        //копирование базовой частиж
    delete [] style;
    style = new char[std::strlen(rs.style) + 1];
    std::strcpy(style, rs.style);
    return *this;
}

std::ostream & operator<<(std::ostream & os, const hasDMA & rs)
{
    //приведение типа для соответствия operator<<(ostream &, const baseDMA &)
    os << (const baseDMA &)rs;
    os << "Style: " << rs.style << std::endl;
    return os;
}
