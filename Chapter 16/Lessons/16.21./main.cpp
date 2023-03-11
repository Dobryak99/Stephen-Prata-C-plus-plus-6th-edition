//vsslice.cpp -- использование срезов valarray
#include <iostream>
#include <valarray>
#include <cstdlib>

const int SIZE = 12;
typedef std::valarray<int> vint;
void show(const vint & v, int cols);

int main()
{
    using std::slice;
    using std::cout;
    vint valint(SIZE);                          //представляет 4 строки по 3 элемента
    int i;
    for(i = 0; i < SIZE; i++)
    {
        valint[i] = std::rand() % 10;
    }
    cout << "Original array:\n";
    show(valint, 3);                            //отображение в виде 3 столбцов
    vint vcol(valint[slice(1,4,3)]);            //извлечение второго столбца
    cout << "Second column:\n";
    show(vcol, 1);                              //отображение в одном столбце
    vint vrow(valint[slice(3,3,1)]);             // извлечение 2-ой строкой
    cout << "Second row:\n";
    show(vrow,3);
    valint[slice(2,4,3)] = 10;                  //присваивания 2 столбцу
    cout << "Set last column to 10:\n";
    show(valint,3);
    cout << "Set first column to sum of next two:\n";
    
    //операция +  не поределена для slice, поэтому преобразуем в valarray<int>
    valint[slice(0,4,3)] = vint(valint[slice(1,4,3)]) + vint(valint[slice(2,4,3)]);
    show(valint,3);
    return 0;
}

void show(const vint & v, int cols)
{
    using std::cout;
    using std::endl;
    int lim = v.size();
    for(int i = 0; i < lim; ++i)
    {
        cout.width(3);
        cout << v[i];
        if(i % cols == cols - 1)
        {
            cout << endl;
        }else cout << ' ';
    }
    if(lim % cols != 0)
    {
        cout << endl;
    }
}
