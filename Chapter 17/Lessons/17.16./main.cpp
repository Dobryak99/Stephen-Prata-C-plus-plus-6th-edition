#include <iostream>
#include <fstream>
#include <string>

int main()
{
    using namespace std;
    string filename;
    cout << "Enter name of the file: ";
    cin >> filename;
    
    //создание объекта выходного потока для нового файла и назанчение ему имени fout
    ofstream fout(filename.c_str());
    fout << "for your eyes only!\n";
    cout << "Enter your secret number: ";
    float secret;
    cin >> secret;
    fout << "Your secret number is " << secret << endl;
    fout.close();
    
    //создание объекта входного потока для нового файла и назначение ему имени fin
    ifstream fin(filename.c_str());
    cout << "Here are the contens of " << filename << ":\n";
    char ch;
    while(fin.get(ch))          //чтение символа из файла
    {
        cout << ch;             //вывод символа
    }
    cout << "Done!\n";
    fin.close();
    return 0;
}
