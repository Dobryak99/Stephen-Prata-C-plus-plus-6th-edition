//worker0.cpp -- методы классов работников
#include "worker.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//Методы Worker

Worker::~Worker() {}

void Worker::Set()
{
    cout << "Enter worker's name; ";
    getline(cin, fullname);
    cout << "Enter worker's ID: ";
    cin >> id;
    while(cin.get() != '\n')
    {
        continue;
    }
}

void Worker::Show() const
{
    cout << "Name: " << fullname << endl;
    cout << "Employee ID: " << id << endl;
}

//Методы Waiter

void Waiter::Set()
{
    Worker::Set();
    cout << "Enter workers panache rating: ";           //ввод индекса элегантности официанта
    cin >> panache;
    while(cin.get() != '\n')
    {
        continue;
    }
}

void Waiter::Show() const
{
    cout << "Category: Waiter\n";
    Worker::Show();
    cout << "Panache rating: " << panache << "\n";
}

//Методы Singer
char * Singer::pv[] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};       //потому что static

void Singer::Set()
{
    Worker::Set();
    cout << "Enter number for singer's vocal range: ";
    int i;
    for(i = 0; i < Vtypes; i++)
    {
        cout << i << ": " << pv[i] << " ";
        if( i % 4 == 3)
        {
            cout << endl;
        }
    }
    if( i % 4 != 0)
    {
        cout << endl;
    }
    while(cin >> voice && (voice < 0 || voice >= Vtypes))
    {
        cout << "Please enter a Value >= 0 and < " << Vtypes << endl;
    }
    while(cin.get() != '\n')
        continue;
}

void Singer::Show() const
{
    cout << "Category: singer\n";
    Worker::Show();
    cout << "Vocal range: " << pv[voice] << endl;
}
