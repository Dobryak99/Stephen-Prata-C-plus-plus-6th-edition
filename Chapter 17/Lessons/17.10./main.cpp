//iomanip.cpp -- использование манипуляторов из iomanip

#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    using namespace std;
    
    //использование новых стандартных манипуляторов
    cout << fixed << right;
    
    //использование манипуляторов iomanip для извлечения
    // квадратного корня и корня четвертой степени
    
    cout << setw(6) << "N" << setw(14) << "square root"
    <<setw(15) << "forth root\n";
    
    double root;        //извлечение конря
    for(int n = 10; n <= 100; n+=10)
    {
        root = sqrt(double (n));
        cout << setw(6) << setfill('.') << n << setfill(' ')
        << setw(12) << setprecision(3) << root << setw(14)
        << setprecision(4) << sqrt(root)
        <<endl;
    }
    return 0;
    
}
