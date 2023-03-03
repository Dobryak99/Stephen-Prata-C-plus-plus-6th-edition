#ifndef PORT_H_
#define PORT_H_

#include <iostream>
using namespace std;

class Port                          //портвейн
{
    private:
        char * brand;
        char style[20];             //например tawny(золотистый), ruby(рубиновый), vintage(марочный)
        int bottles;
    public:
        Port(const char * br = "none", const char * st = "none", int b = 0);
        Port(const Port & p);           // коснтруктор копирования
        virtual ~Port() { delete [] brand; }
        Port & operator=(const Port & p);
        Port & operator+=(int b);            //добавляет b к bottles
        Port & operator-=(int b);           //вычитает b из bottles если это возможно
        int BottleCount() const {return bottles;}
        virtual void Show() const;
        friend ostream & operator<<(ostream & os, const Port & p);
};

class VintagePort : public Port
{
    private:
        char * nickname;                    //т.е. "The Noble", "Old Velvet", 
        int year;                           //год сбора
    public:
        VintagePort();
        VintagePort(const char * br, int b , const char * nn, int y);
        VintagePort(const VintagePort & vp);
        ~VintagePort() {delete [] nickname;}
        VintagePort& operator=(const VintagePort &vp);
        void Show() const;
        friend ostream & operator<<(ostream & os, const VintagePort & vp);
};
#endif
