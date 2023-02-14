#include <iostream>
#include <fstream>
#include <cstdlib>
const int Size = 30;
int main()
{
    using namespace std;
    char filename[Size];   //место для имя файла
    ifstream File;   // объект для обработки файлового ввода
    cout << "Enter the name of the file:";
    cin.getline(filename, Size);
    File.open(filename);    //ассоциирование File с файлом
    // Если файл не удается открыть
    if(!File.is_open())
    {
        cout << "Couldn't open the file " << filename << endl;
        cout << "Programm terminating.\n";
        exit(EXIT_FAILURE);
    }
    char ch;
    int sum = 0;
    File >> ch;
    while(File.good())
    {
        ++sum;
        File >> ch;
        if(ch == ' ')
        {
            sum--;
        }
    }
    cout << sum << " elements in the file(except spaces).\n";
    File.close();
    return 0;
}
