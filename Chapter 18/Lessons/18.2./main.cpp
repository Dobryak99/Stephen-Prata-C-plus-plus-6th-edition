// useless.cpp -- класс с семантикой перевоса
#include <iostream>

using namespace std;

//интерфейс
class Useless
{
private:
    int n;                                  //количество элементов
    char * pc;                              //указатель на данные
    static int ct;                          //количество объектов
    void ShowObject() const;
public:
    Useless();
    explicit Useless(int k);
    Useless(int k, char ch);
    Useless(const Useless & s);              //обычный конструктор копирования
    Useless(Useless && f);                  //констуктор переноса
    ~Useless();
    Useless operator+(const Useless & s) const;
    
    //В версиях копирования и переноса необходима operator=()
    
    void ShowData() const;
};

//Реализация
int Useless::ct = 0;

Useless::Useless()
{
    ++ct;
    n = 0;
    pc = nullptr;
    
    // вызов конструктора по умолчанию; вывод количества объектов
    cout << "Default constructor called; number of object: " << ct << endl;
    ShowObject();
}

Useless::Useless(int k): n(k)
{
    ++ct;
    
    // вызов констуктора int; вывод количества объектов
    cout << "int constructor called; number of objects: " << ct << endl;
    pc = new char[n];
    ShowObject();
}

Useless::Useless(int k, char ch) : n(k)
{
    ++ct;
    
    cout << "int, char constuctor called; number of objects: " << ct << endl;
    pc = new char[n];
    for(int i = 0; i < n; i++)
    {
        pc[i] = ch;
    }
    ShowObject();
}

Useless::Useless(const Useless & f) : n(f.n)
{
    ++ct;
    cout << "copy constructor called; number of objects: " << ct << endl;
    pc = new char[n];
    for(int i = 0; i < n; i++)
    {
        pc[i] = f.pc[i];
    }
    ShowObject();
}

Useless::Useless(Useless && f) : n(f.n)
{
    ++ct;
    cout << "move constuctor called; number of objects: " << ct << endl;
    pc = f.pc;                              //заимствуем адрес
    f.pc = nullptr;                         //установить старый объект в нулевой указатель
    f.n = 0;
    ShowObject();
}

Useless::~Useless()
{
    cout << "Destructor called; object left: " << --ct << endl;
    cout << "deleted object:\n";
    ShowObject();
    delete [] pc;
}

Useless Useless::operator+(const Useless & s) const
{
    cout << "Entering operator+()\n";
    Useless temp = Useless(n + s.n);
    for(int i = 0; i < n; i++)
    {
        temp.pc[i] = pc[i];
    }
    for(int i = n; i < temp.n; i++)
    {
        temp.pc[i] = s.pc[i - n];
    }
    
    cout << "Temp object:\n";
    cout << "Leaving operator+()\n";
    return temp;
}

void Useless::ShowObject() const
{
    cout << "Number of elements: " << n;
    cout << " Data address: " << (void *) pc << endl;
}

void Useless::ShowData() const
{
    if(n == 0)
    {
        cout << "(object empty)";
    }else{
        for(int i = 0; i < n; i++)
        {
            cout << pc[i];
        }
    }
    cout << endl;
}

//приложение
int main()
{
    {
        Useless one(10, 'x');
        Useless two = one;                  // вызов констуктора копирования
        Useless three(20,'o');
        Useless four (one + three);         //вызов operator+(), конструктор переноса
        cout << "object one: ";
        one.ShowData();
        cout << "object two: ";
        two.ShowData();
        cout << "object three: ";
        three.ShowData();
        cout << "object four: ";
        four.ShowData();
    }
}
