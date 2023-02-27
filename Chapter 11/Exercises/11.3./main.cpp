//randwalk.cpp --  использование класса Vector
#include <iostream>
#include <cstdlib>   //прототипы rand(), srand()
#include <ctime>     //прототип time()
#include "11.3.h"
//#include "11.3.cpp"

int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));   //начальное значение для генератора случайных чисел
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    int tries;
    double maximum;
    double minimum;
    double summary;
    long *pvalues = new long[tries];
    cout << "Enter  target distance(q to quit):";
    while(cin >> target)
    {
        cout << "Enter step length: ";
        if(!(cin >> dstep))
            break;
        cout << "Enter number of tries: ";
        cin >> tries;
        for(int i = 0; i < tries; i++)
        {
            while(result.magval() < target)
            {
                direction = rand() % 360;
                step.reset(dstep, direction, Vector::POL);
                result = result + step;
                steps++;
            }
            cout << "#" << i + 1 << " steps: " << steps << "\n";
            pvalues[i] = steps;
            summary += steps;
            steps = 0;
            result.reset(0.0, 0.0);
            cout << endl;
        }
        minimum = maximum = pvalues[0];
        for(int i = 1;i < tries; i++)
        {
            if(pvalues[i] < minimum)
            {
                minimum = pvalues[i];
            }else if(pvalues[i] > maximum)
            {
                maximum = pvalues[i];
            }
        }
        cout << "Maximum steps: " << maximum << "\n";
        cout << "Minimum steps: " << minimum << "\n";
        cout << "Average steps: " << summary / tries << "\n";
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    cin.clear();
    delete [] pvalues;
    while(cin.get() != '\n')
        continue;
    return 0;
}
