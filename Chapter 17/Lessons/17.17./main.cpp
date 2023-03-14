// count.cpp -- подсчет символов в списке файлов
#include <iostream>
#include <fstream>
#include <cstdlib>      //для exit()

// для запуска программы используй терминал и команду ./ main (файл1) (файл2) и т.д. (пример: ./main rome.txt paris.txt)

int main(int argc, char * argv[])
{
    using namespace std;
    if(argc == 1)           //выход при отсутсвии аргументов
    {
        cerr << "Usage: " << argv[0] << " filename[s]\n";
        exit(EXIT_FAILURE);
    }
    ifstream fin;
    long count;
    long total = 0;
    char ch;
    for(int file = 1; file < argc; file++)
    {
        fin.open(argv[file]);       //подключение потока к argv[file]
        if(!fin.is_open())
        {
            cerr << "Could not open " << argv[file] << endl;
            fin.clear();
            continue;
        }
        count = 0;
        while(fin.get(ch))
        {
            count++;
        }
        cout << count << " Characters in " << argv[file] << endl;
        total += count;
        fin.clear();
        fin.close();
    }
    cout << total << " Characters in all files.\n";
    return 0;
}
