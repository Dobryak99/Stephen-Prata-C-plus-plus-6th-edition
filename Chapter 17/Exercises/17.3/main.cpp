//simple programm to copy from one file to another
#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char * argv[])
{
    using namespace std;
    if(argc == 1)
    {
        cerr << "Usage: " << argv[0] << " filenames[0]\n";
        exit(EXIT_FAILURE);
    }
    ofstream fout;
    ifstream fin;

    fout.open(argv[1]);     //открываем входной поток для копирования в него
    if(!fout.is_open())
    {
        cerr << "Can't open " << argv[1] << " file.\n";
        exit(EXIT_FAILURE);
    }
    fin.open(argv[2]);      // открываем выходной поток
    if(!fin.is_open())
    {
        cerr << "Can't open " << argv[2] << " file.\n";
        exit(EXIT_FAILURE);
    }
    char ch;
    while(fin.get(ch))          //считываем до конца файла
    {
        fout << ch;             // выводим в другой файл
    }
    cout << "Done!\n";
    return 0;
}
