// cinexcp.cpp -- cin, генерирующий исключения
#include <iostream>

int main()
{
    using namespace std;
    // установленный бит failbit вызовет генерацию исключения
    cin.exceptions(ios_base::failbit);
    cout << "Enter numbers: ";
    int sum = 0;
    int input;
    try{
        while(cin >> input)
        {
            sum += input;
        }
    }catch(ios_base::failure & bf)
    {
        cout <<bf.what() << endl;
        cout << "O! the horror!\n";
    }
    cout << "Last value entered = " << input << endl;
    cout << "Sum = " << sum <<  endl;
    return 0;
}
