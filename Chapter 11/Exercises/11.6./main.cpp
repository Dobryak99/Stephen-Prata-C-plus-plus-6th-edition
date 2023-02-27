#include "11.6.h"
#include "11.6.cpp"

int main()
{
    Stonewt STN[6] = {230,120,35,0,0,0};
    Stonewt minSTN = STN[0];
    Stonewt maxSTN = STN[0];
    int counter = 0;
    //Setting values
    for(int i = 3; i < 6; i++)
    {
        std::cout << "Enter value: " << i + 1 << ": ";
        STN[i].set_val();
    }

    //Comparison
    for(int i = 0; i < 6; i++)
    {
        if(STN[i] > maxSTN)
        {
            maxSTN = STN[i];
            if(STN[i].comp_val() >= 11)
            {
                counter++;
            }
        }
    }

    for(int i = 0; i < 6; i++)
    {
        if(STN[i] < minSTN)
        {
            minSTN = STN[i];
        }
    }

    std::cout << "Max pounds value: " << maxSTN << std::endl;
    std::cout << "Min pounds value: " << minSTN << std::endl;
    std::cout << "The number of elements that is more than 11 stones: " << counter << std::endl;
    return 0;
}
