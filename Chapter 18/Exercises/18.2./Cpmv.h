#include <iostream>
#include <string>

class Cpmv
{
    public:
        struct Info
        {
            std::string qcode;
            std::string zcode;
        };
    private:
        Info * pi;
    public:
        Cpmv();
        Cpmv(std::string q, std::string z);
        Cpmv(const Cpmv & cp);                      // конструктор копирования
        Cpmv(Cpmv && mv);                           // конструктор переноса
        ~Cpmv() {std::cout << "Object "<< (void *)pi <<" Deleted\n";delete pi;}
        Cpmv & operator=(const Cpmv & cp);
        Cpmv & operator=(Cpmv && mv);
        Cpmv operator+(const Cpmv & obj) const;
        void Display() const;
};

Cpmv::Cpmv()
{
    std::cout << "----------Default constuctor----------" << std::endl;
    pi = new Info;
}

Cpmv::Cpmv(std::string q, std::string z)
{
    std::cout << "----------Constuctor----------" << std::endl;
    pi = new Info;
    pi ->qcode = q;
    pi ->zcode = z;
}

Cpmv::Cpmv(const Cpmv & cp)
{
    std::cout << "----------Copy constuctor----------" << std::endl;
    pi = new Info;
    pi ->qcode = cp.pi->qcode;
    pi ->zcode = cp.pi->zcode;
}

Cpmv::Cpmv(Cpmv && mv)
{
    std::cout << "----------Move constuctor----------" << std::endl;
    pi = mv.pi;
    mv.pi = nullptr;            //есть сомнения
    /*
    mv.pi->qcode = " ";
    mv.pi->zcode = " ";
    */
}

Cpmv & Cpmv::operator=(const Cpmv & cp)
{
    std::cout << "----------Copy assignment----------" << std::endl;
    if(this == &cp)
    {
        return *this;
    }
    delete pi;
    pi = new Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
    return *this;
}

Cpmv & Cpmv::operator=(Cpmv && mv)
{
    std::cout << "----------Move assignment----------" << std::endl;
    if(this == &mv)
    {
        return *this;
    }
    delete pi;
    pi = mv.pi;
    mv.pi = nullptr;
    return *this;
}

Cpmv Cpmv::operator+(const Cpmv & obj) const
{
    std::cout << "----------Operator+----------" << std::endl;
    Cpmv temp;
    temp.pi->qcode = pi->qcode + obj.pi->qcode;
    temp.pi->zcode = pi->zcode + obj.pi->zcode;
    return temp;
}

void Cpmv::Display() const
{
    std::cout << "qcode = " << pi->qcode << ", zcode = " << pi->zcode << std::endl;
}
