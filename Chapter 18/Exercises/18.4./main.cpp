//functor.cpp -- использование класса functor
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>


/*  

Нужно Убрать по заданию

template<class T>
class TooBig
{
private:
    T cutoff;
public:
    TooBig(const T & t) : cutoff(t) {}
    bool operator() (const T & v) { return v > cutoff;}
};

void outint(int n) {std:: cout << n << " ";}

*/
int main()
{
    using std::list;
    using std::cout;
    using std::endl;
    // TooBig<int>f100(100);
    int vals[10] = {50,100,90,180,60,210,415,88,188,201};
    list<int>yadayada(vals, vals + 10);
    list<int>etcetera(vals, vals + 10);
    
    cout << "Original list:\n";
    for_each(yadayada.begin(), yadayada.end(), [&yadayada](int n){std::cout << n << " ";});     //именованная лямбда-функция
    cout << endl;
    
    for_each(etcetera.begin(), etcetera.end(), [&etcetera](int n){std::cout << n << " ";});     //именованная лямбда-функция
    cout << endl;
    yadayada.remove_if([](int n) {return n > 100;});                                            //неименованная лямбда-функция
    etcetera.remove_if([](int n) {return n > 200;});                                            //неименованная лямбда-функция
    
    cout << "trimmed list:\n";
    
    for_each(yadayada.begin(), yadayada.end(), [&yadayada](int n){std::cout << n << " ";});     //именованная лямбда-функция
    cout << endl;
    
    for_each(etcetera.begin(), etcetera.end(), [&etcetera](int n){std::cout << n << " ";});     //именованная лямбда-функция
    cout << endl;
    return 0;
}
