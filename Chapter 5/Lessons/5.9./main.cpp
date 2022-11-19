// forstr2.cpp -- обращение порядка элементов массива
#include <iostream>
#include <string>
int main()
{
    using namespace std;
    cout << "Enter a word: ";
    string word;
    cin >> word;
    // Физическая модификация объекта string
    char temp;
    int i, j;
    for (j = 0 , i = word.size() - 1; j < i; --i,++j)
    {
        temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
    cout << word << "\nDone!\n";
    return 0;
}
