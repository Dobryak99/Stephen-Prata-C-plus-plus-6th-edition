#include <iostream>
#include  "10.6.h"

Move::Move(double a, double b)
{
    x = a;
    y = b;
}

void Move::showmove() const
{
    std:: cout << "X = " << x << "\t"
    << "Y = " << y << "\n";
}

Move Move::add(const Move & m)
{
    x += m.x;
    y += m.y;
    return *this;
}

void Move::reset(double a, double b)
{
    x = a;
    y = b;
}

