//dma.h -- наследование и динамическое выделение памяти

#ifndef DMA_HPP_
#define DMA_HPP_
#include <iostream>


//Базовый класс использующий динамическое выделение памяти
class baseDMA
{
private:
    char * label;
    int rating;
public:
    baseDMA(const char * l = "null", int r = 0);
    baseDMA(const baseDMA & rs);                            //констуктор копирования
    virtual ~baseDMA();
    baseDMA & operator=(const baseDMA & rs);                //оператор присваивания
    friend std::ostream & operator<<(std::ostream & os, const baseDMA &rs);
};


//производный класс без динамического выделения памяти
//деструктор не нужен
//используется неявный констуктор копирования
//используется неявная операция присваивания
class lacksDMA : public baseDMA
{
private:
    enum{COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char * c ="blank", const char * l = "null", int r = 0);
    lacksDMA(const char * c, const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const lacksDMA & rs);
};


//произвоный класс с динамическим выделением памяти
class hasDMA : public baseDMA
{
private:
    char * style;
public:
    hasDMA(const char * s ="none", const char * l = "null", int r = 0);
    hasDMA(const char * s, const baseDMA & rs);
    hasDMA(const hasDMA & rs);                                              //констуктор копирования
    ~hasDMA();
    hasDMA & operator=(const hasDMA & rs);                                  //оператор присваивания
    friend std::ostream & operator<<(std::ostream & os, const hasDMA & rs);
};

#endif
