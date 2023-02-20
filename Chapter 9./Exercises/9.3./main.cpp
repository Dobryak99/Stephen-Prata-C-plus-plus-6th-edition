#include <iostream>
#include <cstring>
#include <new>

const int BUF = 512;
const int N = 2;
char buffer[BUF];   //блок памяти

struct chaff
{
    char dross[20];
    int slag;
};

int main()
{
    using namespace std;
    cout << "\nMemory address: " << (void*) buffer << endl;
    chaff * arr_struct = new /*(buffer)*/ chaff[N];  // remove staples to Variant 1
    char name[100];
    for(int i = 0; i < N; i++)
    {
        cout << "Enter first element of the struct[" << i + 1  << "](char): ";
        cin.get(name,100);
        strcpy(arr_struct[i].dross, name);
        cout << "Enter second element of the struct[" << i + 1 << "](int): ";
        cin >> arr_struct[i].slag;
        cin.get();
    }
    
    for(int i = 0; i < N; i++)
    {
        cout << "First element of struct [" << i + 1 << "] : " << arr_struct[i].dross << endl;
        cout << "It's address: " << &arr_struct[i].dross << endl;
        cout << "Second element of struct [" << i + 1 << "] : " << arr_struct[i].slag << endl;
        cout << "It's address: " << &arr_struct[i].slag << endl;
    }
    cin.get();
    cin.get();
    return 0;
}
