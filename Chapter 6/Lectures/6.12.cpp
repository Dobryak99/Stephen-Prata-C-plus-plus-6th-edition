// jump.cpp -- использование операторов continue и break
#include <iostream>
const int ArSize = 80;
int main()
{
    using namespace std;
    char line[ArSize];
    int space = 0;
    cout << "Enter a line of text:\n";    //запрос на ввод строки текста
    cin.get(line,ArSize);
    cout << "Complete line:\n" << line << endl;   // вывод полной строки
    cout << "Line throught first period:\n";
    for(int i = 0; line[i] != '\0'; i++)
    {
        cout << line[i];   //отображение символа
        if(line[i] == '.')   // завершениеб  если это точка
            break;
        if(line[i] != ' ')   // пропуск отсавшейся части цикла
            continue;
        space++;
    }
    cout << "\n" << space << " spaces\n";
    cout << "Done.\n";
    return 0;
}
