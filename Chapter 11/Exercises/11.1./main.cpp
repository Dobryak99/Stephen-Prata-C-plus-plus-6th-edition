//randwalk.cpp --  использование класса Vector
#include <iostream>
#include <fstream>
#include <cstdlib>   //прототипы rand(), srand()
#include <ctime>     //прототип time();
#include "11.1.h"
//#include "11.1.cpp"

int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));   //начальное значение для генератора случайных чисел
    double direction;
    std::ofstream out;
    out.open("Vector.txt");
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Enter  target distance(q to quit):";
    while(cin >> target)
    {
        cout << "Enter step length: ";
        if(!(cin >> dstep))
            break;
        out << "Target distance: " << target << ", Step length: " << dstep << ".\n";
        out << steps << ": " << result << "\n";
        while(result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;            
            steps++;
            out << steps << ": " << result << "\n";
        }
        out << "After " << steps << " steps, the subject "
        << "has the following location:\n";
        out << result << endl;    //вывод позиции steps шагов
        result.polar_mode();
        out << " or\n" << result << endl;
        out << "Average outward distance per step = "
        << result.magval()/ steps << endl;  //выод среднего расстояния на один шаг
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    cin.clear();
    while(cin.get() != '\n')
        continue;
    return 0;
}
