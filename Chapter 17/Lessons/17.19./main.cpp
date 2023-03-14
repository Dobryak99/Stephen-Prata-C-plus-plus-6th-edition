// binary.cpp -- бинарный ввод-вывод
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

inline void eatline() {while(std::cin.get() != '\n') continue;}

struct planet
{
    char name[20];
    double population;
    double g;           // скорость свободного падения
};

const char * file = "planets.dat";

int main()
{
    using namespace std;
    
    planet pl;
    cout << fixed << right;
    
    //отображение начального содержимого
    ifstream fin;
    fin.open(file, ios_base::in | ios_base::binary);            //бинарный файл
    
    if(fin.is_open())
    {
        cout << "Here're the current contents of the " << file << " file:\n";
        while(fin.read((char *) & pl, sizeof pl))
        {
            cout << setw(20) << pl.name << ": "
            << setprecision(0) << setw(12) << pl.population
            << setprecision(2) << setw(6) << pl.g << endl;
        }
        fin.close();
    }
    
    //добавление новых данных
    ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);
    
    if(!fout.is_open())
    {
        cerr << "Can't open " << file << " file for output.\n";
        exit(EXIT_FAILURE);
    }
    cout << "Enter planet name (enter a blank line to quit): ";
    cin.get(pl.name, 20);
    while(pl.name[0] != '\0')
    {
        eatline();
        cout << "Enter planetary population: ";
        cin >> pl.population;
        cout << "Enter planet's acceleration of gravity: ";
        cin >> pl.g;
        eatline();
        fout.write((char *) & pl, sizeof pl);
        cout << "Enter panet name (Enter a blank line to quit): ";
        cin.get(pl.name, 20);
    }
    fout.close();
    
    //отображение измененного файла
    fin.clear();
    fin.open(file, ios_base::in | ios_base::binary);
    
    if(fin.is_open())
    {
        cout << "Here're the new contents of the " << file << " file:\n";
        while(fin.read((char *) &pl, sizeof pl ))
        {
            cout << setw(20) << pl.name << ": "
            << setprecision(0) << setw(12) << pl.population
            << setprecision(2) << setw(6) << pl.g << endl;
        }
        fin.close();
    }
    cout << "Done.\n";
    return 0;
    
}
