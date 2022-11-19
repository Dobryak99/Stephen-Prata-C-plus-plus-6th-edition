#include <iostream>
int main()
{
    using namespace std;
    int a;
    int b;
    cout << "Enter first integer: ";
    cin >> a;
    cout << "Enter second integer: ";
    cin >> b;
    int num = b - a;
    int sum = 0;
    for (int i = 0; i <= num; i++)
        sum += a + i;
    cout << sum << endl;
    return 0;
}
