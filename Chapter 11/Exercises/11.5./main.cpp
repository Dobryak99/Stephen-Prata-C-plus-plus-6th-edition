#include "11.5.h"
//#include "11.5.cpp"
using std::cout;
using std::endl;

int main()
{
    Stonewt stn1;
    Stonewt stn2(23.7);
    Stonewt stn3(32);

    cout << "Stn1 contain: " << stn1 << endl;
    cout << "Stn2 contain: " << stn2 << endl;
    cout << "Stn3 contain: " << stn3 << endl;

    Stonewt result(0);

    //Sum
    result = stn2 + stn3;
    cout << "Stn2 + Stn3 = " << result << endl;

    //Substraction
    result = 0;
    result = stn3 - stn2;
    cout << "Stn3 - Stn2 = " << result << endl;

    //multiplication
    result = 0;
    result = stn2 * stn3;
    cout << "Stn2 * stn3 = " << result << endl;

    result.set_INTLBS();
    cout << "INTLBS result = " << result << endl;

    result.set_DBLLBS();
    cout << "DBLLBS result = " << result << endl;


    return 0;
}
