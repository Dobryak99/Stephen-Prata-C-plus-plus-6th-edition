//copyir.cpp -- copy() и итераторы
#include <iostream>
#include <iterator>
#include <vector>


int main()
{
    using namespace std;
    
    int casts[10] = {6,7,2,9,4,11,8,7,10,5};
    vector<int> dice(10);
    
    //копирование из массива в вектор
    copy(casts, casts + 10, dice.begin());
    cout << "Let the dice be cast!\n";
    
    //создание итератора ostream
    ostream_iterator<int, char>out_iter(cout, " ");
    
    //копирование из вектора в выходной поток
    copy(dice.begin(), dice.end(), out_iter);
    cout << endl;
    
    cout << "implicit use of reverse iterator.\n";
    //неявное использование обратного итератора
    
    copy(dice.rbegin(), dice.rend(),out_iter);
    cout << endl;
    
    // явное  использование обратного итератора
    cout << "explicit use of reverse iterator.\n";
    vector<int>::reverse_iterator ri;
    for(ri = dice.rbegin(); ri != dice.rend(); ++ri)
    {
        cout << *ri << ' ';
    }
    cout << endl;
    return 0;
}
