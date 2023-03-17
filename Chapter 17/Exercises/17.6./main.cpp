#include "employee.h"
//#include "employee.cpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

const int MAX = 10;

void menu();
void eatline();


using namespace std;

int main()
{
    using namespace std;
    int count  = 0;         //количество сотрудников
    abstr_emp * pc[MAX];
    ifstream fin;
    fin.open("Employees.txt");
    if(!fin.is_open())
    {
        cerr << "Can't open file.\n";
        exit(EXIT_FAILURE);
    }

    if(fin.peek() != EOF)
    {
        int classtype;
        char ch;
        cout << "Here's you staff:\n";
        while((fin >> classtype).get(ch))
        {
            switch(classtype)
            {
                case employee::Employee:    pc[count] = new employee;
                                            pc[count] ->getall(fin);
                                            cout << endl;
                                            count++;
                                            break;
                case employee::Manager:     pc[count] = new manager;
                                            pc[count] -> getall(fin);
                                            cout << endl;
                                            count++;
                                            break;
                case employee::Fink:        pc[count] = new fink;
                                            pc[count] -> getall(fin);
                                            cout << endl;
                                            count++;
                                            break;
                case employee::Highfink:    pc[count] = new highfink;
                                            pc[count] -> getall(fin);
                                            cout << endl;
                                            count++;
                                            break;
                default:                    std::cout << "Reading error!";
                                            exit(EXIT_FAILURE);
            }
        }
        fin.close();
    }

    // Создание рабочих либо добавление новых
    if(count == MAX)
    {
        cout << "Maximum size reached. Clean your file.\n";
    }else{
        ofstream fout;
        fout.open("Employees.txt", ios_base::out | ios_base::app);      // открывать файл в конце(чтобы не произошла перезапись)
        if(!fout.is_open())
        {
            cerr << "Can't open file.\n";
            exit(EXIT_FAILURE); 
        }
        cout << "You can add up to " << MAX - count << " workers.\n";       // если файл был пустой, то можно добавить максимальное число сотрудников
        int choice;
        menu();
        while(cin >> choice && choice != 5)
        {
            eatline();
            switch(choice)
            {
                case 1: pc[count] = new employee;
                        pc[count] ->SetAll();
                        pc[count] -> writeall(fout);
                        count++;
                        break;
                case 2: pc[count] = new manager;
                        pc[count] ->SetAll();
                        pc[count] -> writeall(fout);
                        count++;
                        break;
                case 3: pc[count] = new fink;
                        pc[count] ->SetAll();
                        pc[count] -> writeall(fout);
                        count++;
                        break;
                case 4: pc[count] = new highfink;
                        pc[count] ->SetAll();
                        pc[count] -> writeall(fout);
                        count++;
                        break;
                default:    std::cout << "Wrong input. Try again.\n";
                            break;
            }
            if(count == MAX)
            {
                cout << "Maximum size reached.\n";
                break;
            }
            menu();
        }
        fout.close();
    }

    // вывод новой информации
    cout << "Here's your staff:\n";
    for(int i = 0; i < count; i++)
    {
        pc[i] -> ShowAll();
        cout << endl;
        delete pc[i];
    }
    cout << "Done!\n";
    return 0;


    return 0;
}

void menu()
{
    std::cout << "\nMAIN MENU\n" << "What kind of worker you add:\n"
    << "1)Employee" << setw(15) << "2)Manager\n"
    << "3)Fink" << setw(20) << "4)Highfink\n"
    << "5)Quit\n" << "Your choice: ";
}

void eatline()
{
    while(cin.get() != '\n')
    {
        continue;
    }
}
