// sumfile.cpp -- чтение файла
#include <iostream>
#include <fstream>
#include <cstdlib>  //поддержка exit()
const int SIZE = 60;
int main()
{
    using namespace std;
    char filename[SIZE];
    ifstream inFile;   //объект для обработки файлового ввода
    cout << "Enter name of data file: ";
    cin.getline(filename, SIZE);
    inFile.open(filename);   // ассоциирование inFile с файлом
    if(!inFile.is_open())   //не удалось открыть файл
    {
        cout << "Couldn't open the file " << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    double value;
    double sum = 0.0;
    int count = 0;     //количество прочитанных элементов
    inFile >> value;   //ввод первого значения
    while (inFile.good())   // пока ввод успешени и не достигнут EOF
    {
        ++count;    //еще один элемент прочитан
        sum += value;   //вычесление текущей суммы
        inFile >> value;    // ввод следующего значения
    }
    if (inFile.eof())
        // достигнут конец файла
        cout << "End of file reached.\n";
    else if (inFile.fail())
        // ввод прекращен из-за несоответствия типа данных
        cout << "input terminated by data mismatch.\n";
    else
        //ввод прекращен по неизвестной причине
        cout << "input terminated for unknown reason.\n";
    if(count == 0)
        //данные для обработки отсутствуют
        cout << "No data processed.\n";
    else
    {
        cout << "Item read: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum / count << endl;
    }
    inFile.close();
    return 0;
}
