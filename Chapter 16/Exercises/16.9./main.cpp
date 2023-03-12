
#include <iostream>
#include <ctime>
#include <vector>
#include <list>
#include <algorithm>

//#define CLOCKS_PER_SEC 1000
int rand_num();

int main()
{
    using namespace std;
    srand(time(NULL));
    vector<int> vi0;                    // создание объекта vi0
    for(int i = 0; i < 100000; i++)
    {
        vi0.push_back(rand_num());      //инициализация объекта рандомными числами
    }

    vector<int> vi(vi0.begin(), vi0.end());
    list<int> li(vi0.begin(), vi0.end());
    
    /*
    cout << "\"vi0\" contains:\n";
    for(int i = 0; i < 100000; i++)
    {
        cout << vi0[i] << " ";
    }
    */

    cout << endl;
    cout << "---------------------------------------------\n";
    cout << "Time to sort \"vi\": ";
    clock_t start = clock();            //начало замера
    sort(vi.begin(), vi.end());         // сортировка вектора vi
    clock_t end = clock();              //конец замера
    cout << (double)(end - start)/ CLOCKS_PER_SEC << endl;
    cout << "---------------------------------------------\n";
    cout << "Time to sort \"li\": ";
    start = clock();
    li.sort();
    end = clock();
    cout << (double)(end - start)/ CLOCKS_PER_SEC << endl;

    //li.clear();                         //очищаем li
    copy(vi0.begin(), vi0.end(), li.begin());        //копируем значение vi0 в li

    cout << "---------------------------------------------\n";
    cout << "Time of mixed operations: ";
    start = clock();

    copy(li.begin(), li.end(), vi.begin());
    sort(vi.begin(), vi.end());
    copy(vi.begin(), vi.end(), li.begin());
    end = clock();
    cout << (double)(end - start)/ CLOCKS_PER_SEC << endl;
    cout << "---------------------------------------------\n\n";
    return 0;
}

int rand_num()
{
    int num = rand() % 100 + 1;
    return num;
}

