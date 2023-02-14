#include <iostream>
const int Size = 10;
int main()
{
    using namespace std;
    double donation[Size];
    int i = 0;
    cout << "Enter the donations(type letter to terminate).\n";
    cout << "Donation #1:";
    while(i < Size && cin >> donation[i])
    {
        if(++i < Size)
            cout << "Donation #" << i + 1 << ":";
    }
    double sum = 0;
    for(int j = 0; j < i; j++)
    {
        sum += donation[j];
    }
    cout << "The sum of donations is " << sum << " dollars.\n";
    double average = 0;
    average = sum / i;
    cout << "The average:" << average << endl;
    int count = 0;
    for(int j = 0; j < i; j++)
    {
        if(donation[j] >  average)
            count++;
    }
    cout << "The quantity of donations that bigger than average:" << count << endl;
    return 0;
}
