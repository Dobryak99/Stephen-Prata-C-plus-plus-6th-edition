//placenew1-cpp -- операции new, new с размещением, но без delete
#include <iostream>
#include <string>
#include <new>

using namespace std;
const int BUF = 512;

class Justtesting
{
private:
    string words;
    int number;
public:
    Justtesting(const string & s = "Just Testing" , int n = 0)
    { words = s; number = n; cout << words << " constructed.\n";}
    ~Justtesting() { cout << words << " destroyed\n";}
    void Show() const { cout << words << ", " << number << endl;}
};
int main()
{
    char * buffer = new char[BUF];                  //получение блока памяти
    Justtesting *pc1, *pc2;
    pc1 = new (buffer) Justtesting;                 // Размещение  объекта в buffer
    pc2 = new Justtesting("Heap1" ,20);             // Размещение объекта в куче
    cout << "Memory block addresses:\n" << "buffer: "
    <<(void *)buffer << " heap: " << pc2 << endl;   //вывод адресов памяти
    cout << "Memory contents:\n";                   //вывод содержимого памяти
    cout << pc1 << ": ";
    pc1->Show();
    cout << pc2 << ": ";
    pc2 ->Show();
    Justtesting * pc3, *pc4;
    
    //Фиксация ячейки,  с которой работает new с размещением
    pc3 = new (buffer + sizeof(Justtesting)) Justtesting("Bad ideas", 6);
    pc4 = new Justtesting("Heap2", 10);
    cout << "Memory contains:\n";
    cout << pc3 << ":";
    pc3->Show();
    cout << pc4 << ": ";
    pc4->Show();
    delete pc2;
    delete pc4;
    
    //явное удаление объектов , созданных с new с размещением
    pc3->~Justtesting();                            //уничтожение объекта, на который указывает pc3
    pc1->~Justtesting();                            //уничтожение объекта, на который указывает pc4
    delete [] buffer;
    cout << "Done!\n";
    return 0;
}
