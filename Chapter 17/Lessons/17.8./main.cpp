// setf.cpp -- использование setf() для управления форматированием
#include <iostream>

int main()
{
    using std::cout;
    using std::endl;
    using std::ios_base;
    
    int temperature = 63;
    
    cout << "Today's weather temperature: ";
    cout.setf(ios_base::showpos);           //показать знак +
    cout << temperature << endl;
    
    cout << "For our programming friends, that's\n";
    cout << std::hex << temperature << endl;        //использование шестнадцатеричного представления
    cout.setf(ios_base::uppercase);                 // применение прописных символов в шестнадцатеричном формате
    cout.setf(ios_base::showbase);                  // использование префикса 0х
    
    cout << "or\n";
    cout << temperature << endl;
    cout << "How " << true << "! oops -- How ";
    cout.setf(ios_base::boolalpha);
    cout << true << "!\n";
    return 0;
}
