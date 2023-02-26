//vect.cpp -- методы класса Vector
#include <iostream>
#include <cmath>
#include "vect.hpp"

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
    //вычисляет количество градусов в одном радиане
    const double RAD_TO_DEG = 45.0;  //atan(1.0)   ~= 57.2957795130823
    
    //закрытые методы
    //вычисляет модуль из x и y
    void Vector::set_mag()
    {
        mag = sqrt(x * x + y * y);
    }
    
    void Vector::set_ang()
    {
        if(x == 0 && y == 0)
        {
            ang =0.0;
        }else{
            ang = atan2(y,x);
        }
    }
    
    //устанавливает x по полярным координатам
    void Vector::set_x()
    {
        x = mag * cos(ang);
    }
    //устанавливает y  по по полярным координатам
    void Vector::set_y()
    {
        y = mag * sin(ang);
    }
    
    //Открытые методы
    Vector::Vector()        //конструктор по умолчанию
    {
        x = y = mag = ang = 0.0;
        mode = RECT;
    }
    
    //конструирует вектор по прямоугольным координатам,  если form = RECT
    //(по умолчанию), или по полярным координатам,если form = POL
    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if(form == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }else if(form == POL)
        {
            mag = n1;
            ang = n2 / RAD_TO_DEG;
            set_x();
            set_y();
        }else{
            //Некорректный третий аргумент VECTOR(), вектор устанавливается в 0
            cout << "Incorrect 3rd argument to vector() --";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode =RECT;
        }
    }
    
    //конструирует вектор по прямоугольным координатам,  если form = RECT
    //(по умолчанию), или по полярным координатам,если form = POL
    void Vector::reset(double n1, double n2, Mode form)
    {
        mode = form;
        if(form == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }else if(form == POL)
        {
            mag = n1;
            ang = n2 / RAD_TO_DEG;
            set_x();
            set_y();
        }else{
            //Некорректный третий аргумент VECTOR(), вектор устанавливается в 0
            cout << "Incorrect 3rd argument to vector() --";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode =RECT;
        }
    }
    
    Vector::~Vector()
    {
        
    }
    
    void Vector::polar_mode()   //устанавливает режим полярных координат
    {
        mode = POL;
    }
    
    void Vector::rect_mode()    //устанавливает режим полярных координат
    {
        mode = RECT;
    }
    
    //Перегрузка операций
    //Сложение двух векторов
    Vector Vector::operator+(const  Vector & b) const
    {
        return Vector(x + b.x, y + b.y);
    }
    
    //Вычитание веткотра b из а
    Vector Vector::operator-(const Vector & b) const
    {
        return Vector(x - b.x, y - b.y);
    }
    
    //Смена знака вектора на противоположный
    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }
    
    //Умножение вектора на n
    Vector Vector::operator*(double n) const
    {
        return Vector(n * x, n * y);
    }
    
    //Дружественные методы
    //Умножение n на вектор a
    Vector operator*(double n, const Vector & a)
    {
        return a * n;
    }
    
    //Отображает прямоугольные координаты, если mode = RECT
    //или отображает полярные координаты, если mode = POL
    std::ostream & operator<<(std::ostream & os, const Vector & v)
    {
        if(v.mode == Vector::RECT)
        {
            os << "(x,y) = (" <<v.x << ", " << v.y << ")";
        }else if(v.mode == Vector::POL)
        {
            os << "(m,a) = (" << v.mag << ", " << v.ang * RAD_TO_DEG<< ")";
        }else{
            os << "Vector object mode is invalid";
        }
        return os;
    }
}
