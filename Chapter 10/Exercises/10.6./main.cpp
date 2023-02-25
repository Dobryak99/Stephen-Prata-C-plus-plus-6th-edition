#include <iostream>
#include "10.6.h"
//#include "10.6.cpp"

int main()
{
    Move move1(4.0, 5.0);
    move1.showmove();
    move1.add(move1);
    move1.showmove();
    move1.reset();
    move1.showmove();
    return 0;
}
