//usetime2.cpp -- использование третьей черновой версии класса Time
#include <iostream>
#include "mytime2.hpp"

int main()
{
    using std::cout;
    using std::endl;
    
    Time weeding(4,35);
    Time waxing(2,47);
    Time total;
    Time diff;
    Time adjusted;
    
    cout << "Weeding time = ";
    weeding.Show();
    cout << endl;
    
    cout << "Waxing time = ";
    waxing.Show();
    cout << endl;
    
    cout << "Total work time = ";
    total = weeding + waxing;
    total.Show();
    cout << endl;
    
    diff = weeding - waxing;
    cout << "Weeding time - waxing time = ";
    diff.Show();
    cout << endl;
    
    adjusted = total * 1.5;
    cout << "Adjusted work time = ";
    adjusted.Show();
    cout << endl;
    
    return 0;
}
