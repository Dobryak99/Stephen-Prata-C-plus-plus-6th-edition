// num_test.cpp --использование числовой проверки в цикле
#include <iostream>
int main()
{
    using namespace std;
    cout << "Enter the starting countdown value: ";  //ввод начального значения счетчика
    int limit;
    cin >> limit;
    int i;
    for(i = limit; i; i--)   //завершается когда i = 0
        cout << "i = " << i << endl;
    cout << "done now that i = " << i << endl;
    return 0;
}
