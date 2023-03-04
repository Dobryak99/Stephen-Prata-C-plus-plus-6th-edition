
//twod.cpp -- создание двухмерного массива
#include <iostream>
#include "ArrayTP.hpp"

int main()
{
    using std::cout;
    using std::endl;
    
    ArrayTP<int,10> sums;
    ArrayTP<double, 10> aves;
    ArrayTP<ArrayTP<int, 5>,10> twodee;
    
    int j, i;
    for(i = 0; i < 10; i++)
    {
        sums[i] = 0;
        for(j = 0; j < 5; j++)
        {
            twodee[i][j] = (i + 1) * (j + 1);
            sums[i] += twodee[i][j];
        }
        aves[i] = (double) sums[i] / 10;
    }
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 5; j++)
        {
            cout.width(2);
            cout << twodee[i][j] << ' ';
        }
        cout << ": sum = ";
        cout.width(3);
        cout << sums[i] << " , average = " << aves[i] << endl;
    }
    cout << "Bye!\n";
    return 0;
}
