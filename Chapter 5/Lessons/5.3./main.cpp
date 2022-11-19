// express.cpp -- значение выражений
#include <iostream>
int main()
{
    using namespace std;
    int x;
    cout << "The expresion x = 100 has the value "; // вывод значения х = 100
    cout << (x = 100) << endl;
    cout << "The expresion x < 3 has the value "; // вывод значения х < 3
    cout << (x < 3) << endl;
    cout << "The expresion x > 3 has the value "; // вывод значения х > 3
    cout << (x > 3) << endl;
    cout.setf(ios_base::boolalpha); // новое средство С++
    cout << "The expresion x < 3 has the value "; // вывод значения x < 3
    cout << (x < 3) << endl;
    cout << "The expresion x > 3 has the value "; // вывод значения х > 3
    cout << (x > 3) << endl;
    return 0;
}
