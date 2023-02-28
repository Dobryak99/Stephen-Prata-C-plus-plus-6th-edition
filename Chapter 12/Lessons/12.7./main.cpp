//sayings1.cpp -- использование расширенного класса String
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "string2.hpp"

const int ArSize = 10;
const int MaxLen = 81;

int main()
{
    using namespace std;
    
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
            cout << sayings[i] << endl;         //sayings[i][0] -- вывод первого значения строки
        }
        String * shortest = &sayings[0];        //инициализация первым объектом
        String * first = &sayings[0];
        for(i = 1; i < total; i++)
        {
            if(sayings[i].length() < shortest->length())
            {
                shortest = &sayings[i];
            }
            if(sayings[i] < *first)                                     //сравнение значений
            {
                first = &sayings[i];                                    //присваивание адреса
            }
        }
        cout << "Shortest saying:\n" << *shortest << endl;
        cout << "First alphabetically:\n" << *first << endl;
        srand(time(0));
        int choice = rand() % total;                                    //выбор случайного индекса
        
        //Создание и инициализация объекта String с помощью new
        String * favourite = new String(sayings[choice]);
        cout << "My favourite saying:\n" << *favourite << endl;
        
        delete favourite;
    }else{
        cout << "Not much to say, eh?\n";
    }
    cout << "Bye!.\n";
    return 0;
}
