#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>


class Store
{
    private:
        std::ofstream * p_fout;
    public:
        Store(std::ofstream & os)  { p_fout = &os; }     //указатель получает адрес вывода для файла
        ~Store() {}
        Store & operator()(const std::string & str);
};
Store & Store::operator() (const std::string & str)
{
    int len = str.size();
    p_fout -> write((char *) &len, sizeof(int));     //сохраняем длину
    p_fout -> write(str.data(), len);               //сохранить символы
    return *this;
}

void ShowStr(const std::string & str);

void GetStrs(std::ifstream & ifs, std::vector<std::string> & vistr);


int main()
{
    using namespace std;

    vector<string> vostr;
    string temp;

    //получить строку
    cout << "Enter strings (empty line to quit):\n";
    while(getline(cin, temp) && temp[0] != '\0')
    {
        vostr.push_back(temp);
    }
    cout << "Here is your input:\n";
    for_each(vostr.begin(), vostr.end(), ShowStr);

    //сохранить в файл
    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    //восстановить содержимое
    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if(!fin.is_open())
    {
        cerr << "Couldn't open file for input.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin,vistr);
    cout << "\nHere're the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), ShowStr);
    return 0;
}

void ShowStr(const std::string & str)
{
    std::cout << str << std::endl; 
}

void GetStrs(std::ifstream & ifs, std::vector<std::string> & vistr)
{    
        int len = 0;
        std::string str;
        char ch;

        // убедитесь, что есть что прочитать
        while (ifs.peek() && !ifs.eof())
        {
            ifs.read((char*)&len, sizeof(int));             //считывает количество символов в слове
            for (int i = 0; i < len; i++)                   //пока считывается одно слово
            {
                ifs.read(&ch, sizeof(char));                // считывает символ 
                str.push_back(ch);                          // сохраняет в стринг
            }
            vistr.push_back(str);                           // сохраняет объект string в объект vector
            str.clear();                                    // очищает string
        } 
}
