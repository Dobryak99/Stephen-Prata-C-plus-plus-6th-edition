#include "employee.h"
//#include "employee.cpp"
#include <iostream>

using namespace std;

int main()
{
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl;
    em.ShowAll();
    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout << ma << endl;
    ma.ShowAll();
    fink f1("Matt", "Oggs", "Oiler", "Juno Barr");
    cout << f1 << endl;
    f1.ShowAll();
    highfink hf(ma, "Curly Kew");
    hf.ShowAll();
    cout << "Press any key to continue: ";
    cin.get();
    highfink hf2;
    hf2.SetAll();
    cout << "Using an abstr_emp * pointer:\n";
    abstr_emp * tri[4] = {&em, &f1, &hf, &hf2};
    for(int i = 0; i < 4; i++)
    {
        tri[i] -> ShowAll();
    }
    return 0;
}
