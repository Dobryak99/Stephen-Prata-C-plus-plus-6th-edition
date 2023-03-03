#include "DMA.h"
#include <iostream>
#include <cstring>

DMA::DMA(const char * l)
{
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
}

DMA::DMA(const DMA & rs)
{
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
}

DMA::~DMA()
{
    delete [] label;
}

DMA & DMA::operator=(const DMA & rs)
{
    if(this == &rs)
    {
        return *this;
    }
    delete [] label;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    return *this;
}

void DMA::View() const
{
    std::cout << "Label: " << label << std::endl;
}


baseDMA::baseDMA(const char * l,int r) : DMA(l)
{
    rating = r;
}

baseDMA::baseDMA(const baseDMA & rs, int r) : DMA(rs)
{
    rating = r;
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    if(this == &rs)
    {
        return *this;
    }
    DMA::operator=(rs);
    rating = rs.rating;
    return *this;
}

void baseDMA::View() const
{
    DMA::View();
    std::cout << "Rating: " << rating << std::endl;
}

lacksDMA::lacksDMA(const char * l, const char * c) : DMA(l)
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}


void lacksDMA::View() const
{
    DMA::View();
    std::cout << "Color: " << color << std::endl;
}

hasDMA::hasDMA(const char * l, const char * s) : DMA(l)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & rs, const char * s) : DMA(rs)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
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
    DMA::operator=(rs);
    delete [] style;
    style = new char[std::strlen(rs.style) + 1];
    std::strcpy(style, rs.style);
    return *this;
}

void hasDMA::View() const
{
    DMA::View();
    std::cout << "Style: " << style << std::endl;
}
