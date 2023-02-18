#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
T maxn(T ar[], int number);

const char * maxn(const char * ar[], int number);

int main()
{
    int arr1[6] = {4,2,1,8,6,9};
    double arr2[4] = {2.45, 3.14, 56.3, 23.45};
    cout << "First step.\n";
    cout << maxn(arr1,6) << endl;
    cout << maxn(arr2,4) << endl;
    cout << "Second step.\n";
    const char * p_arr[5] = {"I love you", "More than the sun", "Deeper than the ocean", "Your beauty is irresistible", "I want you so much"};
    
    cout << maxn(p_arr, 5) << endl;
    cout << "Done!" << endl;
    return 0;
}

template <typename T>
T maxn(T ar[], int number)
{
    T maximum = 0;
    for(int i = 0; i < number; i++)
    {
        if(maximum < ar[i])
        {
            maximum = ar[i];
        }
    }
    return maximum;
}

const char * maxn(const char * ar[], int number)
{
    int pmax = 0;
    const char * max = ar[0];
    for(int i = 0; i < number; i++)
    {
        if(strlen(ar[i]) > pmax)
        {
            pmax = strlen(ar[i]);
            max = ar[i];
        }else {
            continue;
        }
    }
    return max;
}
