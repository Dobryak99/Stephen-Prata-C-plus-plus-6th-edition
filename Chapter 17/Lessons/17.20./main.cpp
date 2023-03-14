// random.cpp -- произвольный доступ к бинарному файлу
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

const int LIM = 20;
struct planet
{
    char name[LIM];
    double population;
    double g;
};

const char * file = "planets.dat";
inline void eatline() { while(std::cin.get() != '\n') continue;}

int main()
{
    using namespace std;
    planet pl;
    cout << fixed;
    
    //отображение начального содержимого
    fstream finout;         //потоки чтения и записи
    finout.open(file, ios_base::in | ios_base::out | ios_base::binary);
    
    int ct = 0;         //подсчет количества элементов
    
    if(finout.is_open())
    {
        finout.seekg(0);            //перейти в начало
        cout << "Here're the current contents of the " << file << " file:\n";
        while(finout.read((char *) &pl, sizeof pl))
        {
            cout << ct++ << ": " << setw(LIM) << pl.name
            << ": " << setprecision(0) << setw(12) << pl.population
            << setprecision(2) << setw(6) << pl.g << endl;
        }
        if(finout.eof())            //достигает конца файла
        {
            finout.clear();         //очищает флаг eof
        }else{
            cerr << "Error in reading " << file << ".\n";
            exit(EXIT_FAILURE);
        }
    }else{
        cerr << file << " couldn't be opened -- bye.\n";
        exit(EXIT_FAILURE);
    }
    
    //изменить запись
    cout << "Enter the record number you wish to change: ";
    long rec;
    cin >> rec;
    eatline();          //избавление от символов новой строки
    if(rec < 0 || rec >= ct)
    {
        cerr << "Invalid record number -- bye!\n";
        exit(EXIT_FAILURE);
    }
    streampos place = rec * sizeof pl;          //преобразование в тип streampos
    finout.seekg(place);                        //произвольный доступ
    if(finout.fail())
    {
        cerr << "error on attempted seek.\n";
        exit(EXIT_FAILURE);
    }
    finout.read((char *) &pl, sizeof pl);
    cout << "your selection:\n";
    cout << rec << ": " << setw(LIM) << pl.name
    << ": " << setprecision(0) << setw(12) << pl.population
    << setprecision(2) << setw(6) << pl.g << endl;
    if(finout.eof())
    {
        finout.clear();
    }
    cout << "Enter planet name: ";
    cin.get(pl.name, LIM);
    eatline();
    cout << "Enter planetary population: ";
    cin >> pl.population;
    cout << "Enter planet's acceleration of gravity: ";
    cin >> pl.g;
    finout.seekp(place);                // вернуться назад
    finout.write((char *) &pl, sizeof pl) << flush;
    if(finout.fail())
    {
        cerr << "Error on attempted write\n";
        exit(EXIT_FAILURE);
    }
    
    //отображение измененного файла
    ct = 0;
    finout.seekg(0);            //перейти в начало файла
    cout << "Here're the new contents of the " << file << " file:\n";
    while(finout.read((char *)&pl, sizeof pl))
    {
        cout << ct++ << ": " << setw(LIM) << pl.name
        << ": " << setprecision(0) << setw(12) << pl.population
        << setprecision(2) << setw(6) << pl.g << endl;
    }
    finout.close();
    cout << "Done!\n";
    return 0;
}
