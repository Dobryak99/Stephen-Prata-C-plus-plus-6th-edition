//sayings1.cpp -- использование расширенного класса String
#include <iostream>
#include "string1.hpp"

const int ArSize = 10;
const int MaxLen = 81;

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    
    String name;
    cout << "Hi, what's your name?\n";                          //ввод имени
    cin >> name;
    //ввод поговорки
    cout << name << ", please enter up to " << ArSize << " short sayings <empty line to quit>:\n";
    String sayings[ArSize];                                     //массив объектов
    char temp[MaxLen];                                          //временное хранилище для строки
    int i;
    for(i = 0; i < ArSize; i++)
    {
        cout << i + 1 << ": ";
        cin.get(temp,MaxLen);
        while(cin && cin.get() != '\n')
        {
            continue;
        }
        if(!cin || temp[0] == '\0')                             //пустая строка?
        {
            break;                                              //i не инкрементируется
        }else{
            sayings[i] = temp;
        }
    }
    int total = i;                                              //количестов прочитанных строк
    if(total > 0)
    {
        cout << "Here are your sayings:\n";
        for(i = 0; i < total; i++)
        {
            cout << sayings[i][0] << ": " << sayings[i] << endl;        //sayings[i][0] -- вывод первого значения строки
        }
        int shortest = 0;
        int first = 0;
        for(i = 1; i < total; i++)
        {
            if(sayings[i].length() < sayings[shortest].length())                //problem!!!!
            {
                shortest = i;
            }
            if(sayings[i] < sayings[first])
            {
                first = i;
            }
        }
        cout << "Shortest saying:\n" << sayings[shortest] << endl;
        cout << "First alphabetically:\n" << sayings[first] << endl;
        cout << "This programm used " << String::HowMany() << " string objects. Bye.\n";
    }else{
        cout << "No input! Bye.\n";
    }
    return 0;
}
