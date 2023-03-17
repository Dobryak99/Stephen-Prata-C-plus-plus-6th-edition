#include <iostream>
#include <fstream>
#include <cstdlib>


int main()
{
    using namespace std;

    ifstream fin1("file1.txt");
    if(!fin1.is_open())
    {
        cerr << "Can't open file1.txt file.\n"; 
        exit(EXIT_FAILURE);
    }
    ifstream fin2("file2.txt");
    if(!fin2.is_open())
    {
        cerr << "Can't open file1.txt file.\n"; 
        exit(EXIT_FAILURE);
    }
    ofstream fout("summary.txt");
    if(!fout.is_open())
    {
        cerr << "Can't open file1.txt file.\n"; 
        exit(EXIT_FAILURE);
    }
    char ch;
    while(!fin1.eof() && !fin2.eof())
    {
        while(fin1.get(ch) && ch != '\n')
        {
            fout << ch;
        }
        fout << ' ';
        while(fin2.get(ch) && ch != '\n')
        {
            fout << ch;
        }
        fout << endl;
        fin1.peek();                // просмотр следующего элемента
        fin2.peek();                // просмотр следующего элемента
    }

    //проверка на остаток данных в файлах(если один файл больше другого)
    if(fin1.eof() && !fin2.eof())
    {
        while(fin2.get(ch) && ch != '\n')
        {
            fout << ch;
        }
        fout << '\n';
    }else if(!fin1.eof() && fin2.eof())
    {
        while(fin1.get(ch) && ch != '\n')
        {
            fout << ch;
        }
        fout << '\n';
    }
    fin1.close();
    fin2.close();
    fout.close();
    cout << "Done!\n";
    return 0;

}
