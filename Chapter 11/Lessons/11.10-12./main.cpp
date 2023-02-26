//usetime3.cpp -- использование четвертой черновой версии класса Time
#include <iostream>
#include "mytime3.hpp"

int main()
{
    using std::cout;
    using std::endl;
    
    Time aida(3,45);
    Time tosca(2,48);
    Time temp;
    
    cout << "Aida and Tosca:\n";
    
    cout << aida << "; " << tosca << endl;
    temp = aida + tosca;
    cout << "Aida + Tosca : " << temp << endl;
    temp = aida * 1.17;
    cout << "Aida * 1.17: " << temp << endl;
    cout << "10.0 * Tosca: " << 10.0 * tosca << endl;
    
    return 0;
}
