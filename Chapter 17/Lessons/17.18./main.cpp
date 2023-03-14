// append.cpp -- добавление информации в файл
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

const char * file = "quests.txt";
int main()
{
    using namespace std;
    char ch;
    
    //отображение начального содержимого
    ifstream fin;
    fin.open(file);
    if(fin.is_open())
    {
        cout << "Here're the current contents of the " << file << " file:\n";
        while(fin.get(ch))
        {
            cout << ch;
        }
        fin.close();
    }
    
    //добавление новых имен
    ofstream fout(file, ios::out | ios::app);
    if(!fout.is_open())
    {
        cerr << "Can't open " << file << " file for output.\n";
        exit(EXIT_FAILURE);
    }
    cout << "Enter guest names (Enter a blank line to quit):\n";
    string name;
    while(getline(cin, name) && name.size() > 0)
    {
        fout << name << endl;
    }
    fout.close();
    
    //отображение измененного файла
    fin.clear();
    fin.open(file);
    if(fin.is_open())
    {
        cout << "Here're the current contents of the " << file << " file:\n";
        while(fin.get(ch))
        {
            cout << ch;
        }
        fin.close();
    }
    
    cout << "Done!\n";
    return 0;
}
