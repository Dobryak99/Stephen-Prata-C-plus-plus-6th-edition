#include <iostream>
#include "11.4.h"
//#include "11.4.cpp"

int main()
{
    using std::cout;
    using std::endl;

    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;

    cout << "Aida and Tosca: \n";
    cout << aida << "; " << tosca << endl;
    temp = aida + tosca;
    cout << "Aida + Tosca: " << temp << endl;
    temp = aida * 1.17;
    cout << "Aida * 1.17: " << temp << endl;
    temp = 10.0 * tosca;
    cout << "10.0 * Tosca: " << temp << endl;
    temp = aida - tosca;
    cout << "Aida - Tosca: " << temp <<  endl;
    return 0;
}
