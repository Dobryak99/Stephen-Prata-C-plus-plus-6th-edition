#include <iostream>
using namespace std;

const int Size = 5;

template<typename T>
T max5(T ar[]);

int main()
{
    int arr1[Size] = {5,10,12,3,43};
    double arr2[Size] = {2.14, 3.43,7.43, 5.34,12.123};
    cout << "First array." << endl;
    cout << max5(arr1) << endl;
    cout << "Second array." << endl;
    cout << max5(arr2) << endl;
    cout << "Done!" << endl;
    return 0;
}

template< typename T>
T max5(T ar[])
{
    T maximum = 0;
    for(int i = 0; i < Size; i++)
    {
        if(maximum < ar[i])
        {
            maximum = ar[i];
        }
    }
    return maximum;
}

