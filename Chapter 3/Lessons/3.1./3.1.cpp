// limits.cpp -- нектороые ограничения целых чисел
#include <iostream>
#include <climits>

int main()
{
  using namespace std;
  int n_int = INT_MAX;    //инициализация n_int максимальным значением int
  short n_short = SHRT_MAX;
  long n_long = LONG_MAX;
  long long n_llong = LLONG_MAX;
  
  //операция sizeof выдает размер типа или переменной
  cout << "int is " << sizeof(int) << " bytes.\n";
  cout << "short is " << sizeof n_short << " bytes.\n";
  cout << "long is " << sizeof n_long << " bytes.\n\n";
  cout << "long long is " << sizeof n_llong << " bytes.\n\n";
  cout << endl;
  
  cout << "Maximum values:" << endl;
  cout << "int: " << n_int << endl;
  cout << "short: " << n_short << endl;
  cout << "long: " << n_long << endl;
  cout << "long long: " << n_llong << endl;
  
  cout << "Minimum int value = " << INT_MIN << endl;
  cout << "Bits per byte = " << CHAR_BIT << endl;
  return 0;
}
