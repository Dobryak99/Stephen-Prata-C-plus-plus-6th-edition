#include <iostream>
#include "cow.h"
#include "cow.cpp"


int main()
{
    Cow cow1;
    Cow cow2("Nancy", "Eating grass", 320);
    Cow cow3("Marry", "Walking in the field", 343);
    std::cout << "Here's our farm:\n";
    cow1.ShowCow();
    cow2.ShowCow();
    cow3.ShowCow();

    cow1 = cow2;

    std::cout << "Cow1 = Cow2: \n";
    cow1.ShowCow();

    return 0;

}
