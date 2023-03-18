// useless.cpp -- класс с семантикой перевоса
#include <iostream>
#include <utility>

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
    Useless(int k,char ch);
    Useless(const Useless & f);             //обычный конструктор копирования
    Useless(Useless && f);                  //констуктор переноса
    ~Useless();
    Useless operator+(const Useless & f) const;
    Useless & operator=(const Useless & f); // операция присваивания с копированием
    Useless & operator=(Useless && f);      //операция присваивания с перемещением
    void ShowData() const;
};

//Реализация
int Useless::ct = 0;

Useless::Useless()
{
    ++ct;
    n = 0;
    pc = nullptr;
}

Useless::Useless(int k): n(k)
{
    ++ct;
    pc = new char[n];
}

Useless::Useless(int k,char ch) : n(k)
{
    ++ct;
    pc = new char[n];
    for(int i = 0; i < n; i++)
    {
        pc[i] = ch;
    }
}

Useless::Useless(const Useless & f) : n(f.n)
{
    ++ct;
    pc = new char[n];
    for(int i = 0; i < n; i++)
    {
        pc[i] = f.pc[i];
    }
}

Useless::Useless(Useless && f) : n(f.n)
{
    ++ct;
    pc = f.pc;                              //заимствуем адрес
    f.pc = nullptr;                         //установить старый объект в нулевой указатель
    f.n = 0;
}

Useless::~Useless()
{
    delete [] pc;
}

Useless & Useless::operator=(const Useless & f)
{
    cout << "copy assignment operator called:\n";
    if(this == &f)
    {
        return *this;
    }
    delete [] pc;
    n = f.n;
    pc = new char[n];
    for(int i = 0; i < n; i++)
    {
        pc[i] = f.pc[i];
    }
    return *this;
}

Useless & Useless::operator=(Useless && f)
{
    cout << "move assignment operator called:\n";
    if(this == &f)
    {
        return *this;
    }
    delete [] pc;
    n = f.n;
    pc = f.pc;
    f.n = 0;
    f.pc = nullptr;
    return *this;
}

Useless Useless::operator+(const Useless & f) const
{
    Useless temp = Useless(n + f.n);
    for(int i = 0; i < n; i++)
    {
        temp.pc[i] = pc[i];
    }
    for(int i = n; i < temp.n; i++)
    {
        temp.pc[i] = f.pc[i - n];
    }
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
        Useless one(10,'x');
        Useless two = one + one;                  //вызов конструктора с переносом
        cout << "Object one: ";
        one.ShowData();
        cout << "Object two: ";
        two.ShowData();
        Useless three, four;
        cout << "Three = one\n";
        three = one;                                //автоматическое присваивание с копированием
        cout << "Now object three: ";
        three.ShowData();
        cout << "and object one: ";
        one.ShowData();
        cout << "fout = one + twon\n";
        four = one + two;                           //автоматическое присваивание с переносом
        cout << "now object four: ";
        four.ShowData();
        cout << "four = move(one)\n";
        four = move(one);                           //принудительное присваивание с переносом
        cout << "now object four = ";
        four.ShowData();
        cout << "and object one = ";
        one.ShowData();
    }
}
