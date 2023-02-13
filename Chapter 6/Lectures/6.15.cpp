// outfile.cpp -- запсиь в файл
#include <iostream>
#include <fstream>   //для файлового ввода и вывода
int main()
{
    using namespace std;
    char automobile[50];
    int year;
    double a_price;
    double d_price;
    ofstream OutFile;    //создание объекта для вывода
    OutFile.open("test.txt");  // ассоциирование его с файлом
    cout << "Enter the make and model of automobile: ";   //ввод производителя и модели
    cin.getline(automobile,50);
    cout << "Enter the model year: ";
    cin >> year;
    cout << "Enter the original asking price: ";  //ввод начальной цены
    cin >> a_price;
    d_price = 0.913 * a_price;
    
    // Отображение информации на экране с помощью cout
    cout << fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    cout << "Make and model: " << automobile << endl;
    cout << "Year: " << year << endl;
    cout << "Was asking $" << a_price << endl;
    cout << "Now asking $" << d_price << endl;
    
    // вывод той же информации с использованием  OutFile вместо cout
    OutFile << fixed;
    OutFile.precision(2);
    OutFile.setf(ios_base::showpoint);
    OutFile << "Make and model: " << automobile << endl;
    OutFile << "Year: " << year << endl;
    OutFile << "Was asking $" << a_price << endl;
    OutFile << "Now asking $" << d_price << endl;
    OutFile.close();
    return 0;
}
