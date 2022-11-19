// textin3.cpp -- чтение символов до конца файла
#include <iostream>
int main()
{
    using namespace std;
    char ch;
    int count = 0;
    cin.get(ch);   //попытка чтения символа
    while(cin.fail() == false)   // проверка на EOF
    {
        cout << ch;
        ++count;
        cin.get(ch);
    }
    cout << endl << count << " characters read\n";
    return 0;
}
